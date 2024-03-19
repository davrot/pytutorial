# error: rpmdbNextIterator: skipping 

## Top

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

If we do

```shell
dnf -y update
```

then we get this error message: 

```shell
error: rpmdbNextIterator: skipping h#   36674 
Header RSA signature: BAD (header tag 268: invalid OpenPGP signature: Parsing an OpenPGP packet:
  Failed to parse Signature Packet
      because: Signature appears to be created by a non-conformant OpenPGP implementation, see <https://github.com/rpm-software-management/rpm/issues/2351>.
      because: Malformed MPI: leading bit is not set: expected bit 8 to be set in    10110 (16))
Header SHA256 digest: OK
Header SHA1 digest: OK
error: rpmdbNextIterator: skipping h#   36674 
Header RSA signature: BAD (header tag 268: invalid OpenPGP signature: Parsing an OpenPGP packet:
  Failed to parse Signature Packet
      because: Signature appears to be created by a non-conformant OpenPGP implementation, see <https://github.com/rpm-software-management/rpm/issues/2351>.
      because: Malformed MPI: leading bit is not set: expected bit 8 to be set in    10110 (16))
Header SHA256 digest: OK
Header SHA1 digest: OK
The downloaded packages were saved in cache until the next successful transaction.
You can remove cached packages by executing 'dnf clean packages'.
Error: An rpm exception occurred: package not installed
```

With 

```shell
rpm -qa >/dev/null 2> error.log
cat error.log | grep "error: rpmdbNextIterator: skipping h#" | awk -c '{print "rpm -q --nosignature --querybynumber " $5 }' | sort -u | sh
```

we can check which packages have a problem. 

With 

```shell
rpm -qa >/dev/null 2> error.log
cat error.log | grep "error: rpmdbNextIterator: skipping h#" | awk -c '{print "rpm -e --nosignature --nodeps $(rpm -q --nosignature --querybynumber " $5 ")"}' | sort -u | sh
```

we remove those package. However you need to make sure that these are not important packages and that you reinstall the updated version via dnf afterwards. 

In the case of intel oneapi:

```shell
dnf -y install --best --allowerasing intel-aikit
dnf -y install --best --allowerasing intel-basekit
dnf -y install --best --allowerasing intel-dlfdkit
dnf -y install --best --allowerasing intel-hpckit
dnf -y install --best --allowerasing intel-iotkit
```

And don't forget to do the update you wanted to do:

```shell
dnf -y install --best --allowerasing
```

