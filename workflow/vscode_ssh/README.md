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

* HostName gate1: Can the the name or the IP of your ssh target
* User sshtest : Well, here you need to put your user name in.
* ForwardX11 yes : Allows you to view graphical from the other side
* Port 22 : This is the default port for the ssh connection. This can be also something else.
* XAuthLocation C:\Progra~1/VcXSrv/xauth.exe : In the case of a Windows 10/11, you need a X Window Server if you need to stream graphical windows to your local machine. Under Linux this is typically included and can be ignored. Under Windows you need a X Server. I tested the [VcXsrv Windows X Server](https://sourceforge.net/projects/vcxsrv/) sucessfully. 

Notes about the Windows 10/11 X Window Server: Last time I tested it, I had to add two Windows environment variables (you find the button "Environment Variables..." under system properties). Add under the User Variable section (The upper box under Environment Variables)

**DISPLAY**

with

127.0.0.1:0.0

and 

**TMPDIR** 

will it with the value of variable TMP

Also also the X Server needs to run. Means you have to start it if you want to use it... I used Multi Window Mode.

## Using it

Select the connection you want:

![image9](2022-04-01_17-40.png)

Enter your password:

![image10](2022-04-01_17-41.png)

Be connected:

![image11](2022-04-01_17-43_0.png)

The first time you make a connection to a system, you need to check if all extensions are there. Typically they are not. Just scroll through the list of "installed" extensions and click on install... again...  

![image12](2022-04-01_17-45.png)

Side note: You can use the terminal under VS code as a terminal running on the ssh target computer. Or in other word: You can use the terminal to create directories via mkdir and move files around. Or even more complicated programs: 

![image13](2022-04-01_17-52_0.png)

## Exchanging files between computers

There are many options to exchange files via ssh between computers. However [filezilla **client**](https://filezilla-project.org/download.php?type=client)!!! is a nice too that is available for Windows and Linux alike. Many Linux distributions have Filezilla already in their package repositories. 

First time you start it, you want to got into the connection settings:

![image14](2022-04-01_18-09_0.png)

Create a new connection and name the parameter setting accordingly:

![image15](2022-04-01_18-11_0.png)

Now you need to put in the information about your ssh connection:

![image16](2022-04-01_18-13_0.png)

* Switch to SFTP
* Enter the hostname or ip
* Enter the port (default is 22)
* Enter your user name
* Add you password or better set to ask for password
 
Press OK to save the information.

Now the configured connection is available:

![image17](2022-04-01_18-16.png)

It will ask you for your password:

![image18](2022-04-01_18-17.png)

And the first time you connect to the ssh server (or in the case the server was replaced by the admin) you will get this message:

![image19](2022-04-01_18-17_1.png)

After OK you can shove files / directories from one side to the other.

![image20](2022-04-01_18-20_0.png)

