# ZeroMQ -- Connecting computers via message queue
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

[ZeroMQ](https://zeromq.org/get-started/) is a simple to implement way to transfer data between server & client application. 
It is available for a vast range of programming languages. Including Python [PyZMQ](https://pyzmq.readthedocs.io/en/latest/index.html). 
It has a [lot of options](https://zguide.zeromq.org/), including broadcasting. I will only present a very simple example because most of it we don't need.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


## Commands

|||
|---|---|
|[zmq.Context](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Context)|	Create a zmq Context|
|[zmq.Context.socket](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Context.socket)|	Create a Socket associated with this Context.|
|[zmq.Socket](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket)|	The ZMQ socket object|
|[zmq.Socket.bind](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.bind)|	Bind the socket to an address.|
|[zmq.Socket.connect](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.connect)|	Connect to a remote 0MQ socket.|
|[zmq.Socket.recv](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.recv)|	Receive a message|
|[zmq.Socket.recv_json](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.recv)|	Receive a Python object as a message using json to serialize.|
|[zmq.Socket.recv_pyobj](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.recv_pyobj)|	Receive a Python object as a message using pickle to serialize.|
|[zmq.Socket.recv_string](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.recv_string)|	Receive a unicode string, as sent by send_string.|
|[zmq.Socket.recv_multipart](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.recv_multipart)|	Receive a multipart message as a list of bytes or Frame objects|
|[zmq.Socket.send](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.send)|	Send a single zmq message frame on this socket.|
|[zmq.Socket.send_json](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.send_json)|	Send a Python object as a message using json to serialize.|
|[zmq.Socket.send_pyobj](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.send_pyobj)|	Send a Python object as a message using pickle to serialize.|
|[zmq.Socket.send_string](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.send_string)|	Send a Python unicode string as a message with an encoding.|
|[zmq.Socket.send_multipart](https://pyzmq.readthedocs.io/en/latest/api/zmq.html#zmq.Socket.send_multipart)|	Send a sequence of buffers as a multipart message.|

## Socket Types

There are many [socket types](https://libzmq.readthedocs.io/en/latest/zmq_socket.html). I will only quote the two relevant ones for this example from the API documentation:

### ZMQ_REQ

> A socket of type ZMQ_REQ is used by a client to send requests to and receive replies from a service. This socket type allows only an alternating sequence of zmq_send(request) and subsequent zmq_recv(reply) calls. Each request sent is round-robined among all services, and each reply received is matched with the last issued request.
> 
> If no services are available, then any send operation on the socket shall block until at least one service becomes available. The REQ socket shall not discard messages.

**Summary of ZMQ_REQ characteristics**

|||
|---|---|
|Compatible peer sockets|	ZMQ_REP, ZMQ_ROUTER|
|Direction|	Bidirectional|
|Send/receive pattern|	Send, Receive, Send, Receive, …|
|Outgoing routing strategy|	Round-robin|
|Incoming routing strategy|	Last peer|
|Action in mute state|	Block|

### ZMQ_REP

> A socket of type ZMQ_REP is used by a service to receive requests from and send replies to a client. This socket type allows only an alternating sequence of zmq_recv(request) and subsequent zmq_send(reply) calls. Each request received is fair-queued from among all clients, and each reply sent is routed to the client that issued the last request. If the original requester does not exist any more the reply is silently discarded.

**Summary of ZMQ_REP characteristics**

|||
|---|---|
|Compatible peer sockets|	ZMQ_REQ, ZMQ_DEALER|
|Direction|	Bidirectional|
|Send/receive pattern|	Receive, Send, Receive, Send, …|
|Incoming routing strategy|	Fair-queued|
|Outgoing routing strategy|	Last peer|

## Simple example where we move np.ndarrays around

### Client

```python
import zmq
import numpy as np

context = zmq.Context()

socket = context.socket(zmq.REQ)
# We connect to the localhost at port 5555
socket.connect("tcp://localhost:5555")

# Generating a random np matrix
rng = np.random.default_rng()
np_array = rng.random((100, 10))

# Send it over the wire
socket.send_pyobj(np_array)

# We get the squared version back 
np_array_return = socket.recv_pyobj()

# Check if we get a correct return message 
print(type(np_array_return))

np_array = np_array**2

print("Difference:")
print(np.sum(np.abs(np_array_return - np_array)))
```

Output:

```python
<class 'numpy.ndarray'>
Difference:
0.0
```

### Server

```python
import zmq

context = zmq.Context()
socket = context.socket(zmq.REP)
# Listen at port 5555
socket.bind("tcp://*:5555")

while True:
    # We should receive a numpy array
    input_np = socket.recv_pyobj()

    # Let's do something with this information
    print(type(input_np))
    print(input_np.shape)
    input_np = input_np**2

    # We send the results back
    socket.send_pyobj(input_np)
```

Output:

```python
<class 'numpy.ndarray'>
(100, 10)
```

## Non-blocking

There is this option to receive packages in a non blocking way: 

```python
    confirm = False
    while not confirm:
        try:
            packet_in = socket.recv_pyobj(zmq.NOBLOCK)
            confirm = True
        except zmq.error.Again:
            pass
```


