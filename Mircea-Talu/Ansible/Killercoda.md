# Ansible

[Killercoda labs](https://killercoda.com/het-tanis/course/Ansible-Labs)

## Setup

```bash
apt install -y ansible

ansible --version
```

## Ansible-Doc

```bash
ansible-doc --version
```

[ansible-doc](https://docs.ansible.com/ansible/latest/cli/ansible-doc.html) is used to display information on modules installed in Ansible libraries

For the following commands, we need to create a file where we specify our hosts. In this case, we use /root/hosts.

This file can be in .ini or .yaml format.

## Ansible Servers

```bash
ansible servers -i /root/hosts -m ping
```

ansible servers defines and runs a single task 'playbook' against a set of **hosts**

## Ansible Inventory

```bash
ansible-inventory -i /root/hosts --list
```

ansible-inventory shows Ansible **inventory information**

## Ad Hoc to gather data

### Check server uptime

```bash
ansible servers -i /root/hosts -m shell -a 'uptime'
```

### Get host information using Setup module

```bash
ansible servers -i /root/hosts -m setup
```

This command gives you a **lot** of information about hosts (can be very useful).

You can cut some of it and only check the host distribution information.

```bash
ansible servers -i /root/hosts -m setup -a 'filter=ansible_distribution'
```

**Note**: Apparently this thing uses Python.

You can cut the output a bit more to check the host time information.

```bash
ansible servers -i /root/hosts -m setup -a 'filter=ansible_date_time'
```

## Ad Hoc to copy and edit

This command creates a directory /opt/deployment on every host.

```bash
ansible servers -i /root/hosts -m file -a 'path=/opt/deployment state=directory'
```

This command copies a file from the host to each of the servers in /root/hosts.

```bash
ansible servrs -i /root/hosts -m copy -a 'src=/root/configfile.cfg dest=/opt/deployment'
```

You can check if the file was copied on each host.

```bash
ansible servers -i /root/hosts -m shell -a 'ls /opt/deployment'
```

Up next, you can edit the file. In this case, we want to change var1 from 000000 to 111111.

```bash
ansible servers -i /root/hosts -m lineinfile -a "path=/opt/deployment/configfile.cfg regexp='^var1' line='var1=111111'"
```

Finally, we can check if the change took place.

```bash
ansible servers -i /root/hosts -m shell -a 'cat /opt/deployment/configfile.cfg'
```

## Ansible Playbooks

Allows you to create a **declarative** file (.yml) which specifies the playbook.

It is not practical to run 100 hundred individual commands as your system grows.

```yaml
---
- name: Start of Deployer playbook
  hosts: servers
  vars:
  gather_facts: True
  become: False
  tasks:

    - name: Copy deploy.tar.gz over at {{ ansible_date_time.iso8601_basic_short }}
      copy:
        src: /root/deploy.tar.gz
        dest: /opt/deploy.tar.gz
        checksum: c6cd21b75a4b300b9228498c78afc6e7a831839e
```

Run the Playbook

```bash
ansible-playbook -i /root/hosts /root/deploy.yml
```
