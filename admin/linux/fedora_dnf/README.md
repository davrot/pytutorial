# When dnf fails.

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Let us assume the dnf update inbetween. You lost the remote connection to the computer where the update was running or systemd oom killed the dnf task. 

Now you are stuck in dnf limbo. How to get out of it with less effort as possible?  


### Try 1

```shell
dnf -y remove --duplicates 2> error.log
cat error.log | awk -F 'from install of|conflicts with file from package' '{print $2}' | sort -u | awk 'NF' | sed s/"^ "/"dnf -y reinstall "/g | sh
```

### Try 2

```shell
dnf -y remove --duplicates 2> error.log
cat error.log | awk -F 'from install of|conflicts with file from package' '{print $2}' | sort -u | awk 'NF' 
```
