# Check if the port for torchrun is open via ncat

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


This is my script (connection_test.sh) that tests if a connection between two computer of a given port is possible: 

You need the master_ip and master_port: 

```shell
master_ip="10.10.10.10"
master_port="40001"
python_file="main.py"

ip_check=`ip addr | grep $master_ip | wc -l`

if [[ $ip_check == "1" ]]
then
    echo "Master"
    echo "OK OK OK OK OK OK OK" | ncat -l -p $master_port
else
    echo "Client"
    ncat $master_ip $master_port
```

If this fails, the port is already used or your firewall settings is blocking it. 

