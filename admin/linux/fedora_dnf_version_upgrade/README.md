# Updating to the next version

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

Before starting, you need to install the dnf-plugin-system-upgrade package. 

```shell
dnf install dnf-plugin-system-upgrade
```

After that, this is normally enough (example for 37 -> 38):

```shell
dnf -y system-upgrade download --refresh --releasever=38 --allowerasing --best --skip-broken 2> error.log ; dnf system-upgrade reboot
cat error.log | grep -v "^No match for group package" | grep -v "^Error:"
```

However, you might encouter problems like: 

### Remove obsolete packages 

We can analyse the error.log file: 

```shell
echo "Check if these packages can be deleted:"
cat error.log | grep -v "^No match for group package" | grep -v "^Error:" | grep "does not belong to a distupgrade repository"
```

```shell
Check if these packages can be deleted:
  - jack-audio-connection-kit-example-clients-1.9.21-3.fc37.x86_64 from @System  does not belong to a distupgrade repository
```

Now we can try to remove the obsolte package carefully(!!!): 

```shell
yum remove --noautoremove jack-audio-connection-kit-example-clients
```

After that we can try to run the upgrage again: 

```shell
dnf -y system-upgrade download --refresh --releasever=38 --allowerasing --best --skip-broken 2> error.log ; dnf system-upgrade reboot
cat error.log | grep -v "^No match for group package" | grep -v "^Error:"
```


