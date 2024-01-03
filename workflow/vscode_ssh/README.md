# Working remotely via ssh
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## Top

Develop your code with [VS code remotely via a ssh connection](https://code.visualstudio.com/docs/remote/ssh).

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Installation

We need to install the Remote ssh extension

![image0](image0.png)

and these one too:

![image1](image1.png)

However, the second one should be installed automatically. 

## Configuration

![image2](2022-04-01_17-17.png)

![image3](2022-04-01_17-22.png)

Now you can enter your user and computer name / ip address of the ssh target:

![image4](2022-04-01_17-24.png)

It asks where to store the information (i.e. ssh key). Select the one in your home directory: 

![image5](2022-04-01_17-25.png)

Now we can review the settings by clicking on "Open Config": 

![image6](2022-04-01_17-25_1.png)

Or later by clicking here

![image7](2022-04-01_17-28.png)

and then here

![image8](2022-04-01_17-29.png)

In the moment my configuration looks like:

```python
Host gate1
  HostName gate1
  User sshtest
```

Typical options:

** HostName gate1: Can the the name or the IP of your ssh target
** User sshtest : Well, here you need to put your user name in.
** ForwardX11 yes : Allows you to view graphical from the other side
** Port 22 : This is the default port for the ssh connection. This can be also something else.
** XAuthLocation C:\Progra~1/VcXSrv/xauth.exe : In the case of a Windows 10/11, you need a X Window Server if you need to stream graphical windows to your local machine. Under Linux this is typically included and can be ignored. Under Windows you need a X Server. I tested the [VcXsrv Windows X Server](https://sourceforge.net/projects/vcxsrv/) sucessfully. 

Notes about the Windows 10/11 X Window Server: Last time I tested it, I had to add two Windows environment variables (you find the button "Environment Variables..." under system properties). Add under the User Variable section (The upper box under Environment Variables)

**DISPLAY**

with

127.0.0.1:0.0

and 

**TMPDIR** 

will it with the value of variable TMP

Also also the X Server needs to run. Means you have to start it if you want to use it... I used Multi Window Mode.

```python
```
