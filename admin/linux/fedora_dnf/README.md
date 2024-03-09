# When dnf fails.

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Let us assume the dnf update inbetween. You lost the remote connection to the computer where the update was running or systemd oom killed the dnf task. 

Concerning systemd-oomd, you turn it off via: 

```shell
systemctl disable --now systemd-oomd
```

Now you are stuck in dnf limbo. How to get out of it with less effort as possible?  

## Try 0

If you can do this without an error then you are on a good way: 

```shell
dnf -y remove --duplicates 
```

## Try 1

Well, if try 0 resulted in conflicts, we can try to solve them semi-autotamic: 

```shell
dnf -y remove --duplicates 2> error.log
cat error.log | awk -F 'from install of|conflicts with file from package' '{print $2}' | sort -u | awk 'NF' | sed s/"^ "/"dnf -y reinstall "/g | sh
dnf -y remove --duplicates 2> error.log
```

## Try 2

We end up here if errors after try 1 still remained: 

```shell
cat error.log | awk -F 'from install of|conflicts with file from package' '{print $2}' | sort -u | awk 'NF' 
```

Now we need to deal with the remaining problem manually. This package is still broken: 

```shell
darktable-4.4.2-1.fc37.x86_64
```

This does not work: 

```shell
[root ~]# dnf -y reinstall darktable-4.4.2-1.fc37.x86_64
Last metadata expiration check: 0:03:59 ago on Sat 09 Mar 2024 04:17:07 AM CET.
Package darktable available, but not installed.
No match for argument: darktable-4.4.2-1.fc37.x86_64
Error: No packages marked for reinstall.
```

Okay, maybe we need to delete the old package manually: 

```shell
cat error.log | awk -F 'conflicts with file from package' '{print $2}' | sort -u | awk 'NF'
```

The problem lies with:

```shell
 darktable-tools-noise-4.0.1-2.fc37.x86_64
```

We will remove it carefully(!!!). Don't use -y and check the list if something important is on the to-be-deleted list:  

```shell
dnf remove --noautoremove darktable-tools-noise-4.0.1-2.fc37.x86_64
```
Now we should be able to do this: 

```shell
dnf -y remove --duplicates 
```

## Finalize 

Now we can finalize the repair with:

```shell
dnf -y update --best --allowerasing --skip-broken
```

or 

```shell
dnf -y --enablerepo=* update --best --allowerasing --skip-broken
```

Depending on if you want to include other non-default repos from your repo-list. 

## Protected packages 

If you get complaints about protected system packages, you can disable this protection by: 

```shell
mv /etc/dnf/protected.d /etc/dnf/protected.d_xxx
```

However, you should restore the protection later:

```shell
mv /etc/dnf/protected.d_xxx /etc/dnf/protected.d
```
