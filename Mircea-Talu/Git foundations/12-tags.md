# Tags

## Tags are very powerful when used correctly
* syntax : **git tag -a (v1.0) -m ("version 1.0 initial state")**
* **git tag** returns all tags
* **git show (v1.0)** : shows detailed information about commit or whatever tagged by the **tag** v1.0
* we can also tag by commit (by default the **tag** is for the current **HEAD**)
* **git tag -a (version) -m (message) (commit hash)**
* navigation through tags is very easy
* **git tag** : display tags
* **git checkout (tag)**
* example : git checkout v1.0
* **git describe** or **git describe --tags** tells us which tag we are currently on
* **git tag -d v1.0** : deletes tag v1.0 ; **-d** argument is used for deletion
