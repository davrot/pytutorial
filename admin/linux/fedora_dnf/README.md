# When dnf fails.

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Let us assume the dnf update inbetween. You lost the remote connection to the computer where the update was running or systemd oom killed the dnf task. 

Concerning systemd-oomd, you turn it off via: 

```shell
systemctl disable --now systemd-oomd
```

Now you are stuck in dnf limbo. How to get out of it with less effort as possible?  

### Try 0

If you can do this without an error then you are on a good way: 

```shell
dnf -y remove --duplicates 
```

### Try 1

Well, if try 0 resulted in conflicts, we can try to solve them semi-autotamic: 

```shell
dnf -y remove --duplicates 2> error.log
cat error.log | awk -F 'from install of|conflicts with file from package' '{print $2}' | sort -u | awk 'NF' | sed s/"^ "/"dnf -y reinstall "/g | sh
dnf -y remove --duplicates 2> error.log
```

### Try 2

We end up here if errors after try 1 still remained: 

```shell
cat error.log | awk -F 'from install of|conflicts with file from package' '{print $2}' | sort -u | awk 'NF' 
```
