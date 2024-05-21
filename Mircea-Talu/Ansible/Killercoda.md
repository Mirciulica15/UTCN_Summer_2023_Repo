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

## Ansible Playbooks to Deploy Application

Let us create a multi-task playbook.

First task copies an archive to each of the hosts.

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

The next task creates a directory to untar into.

```yaml
    - name: Create directory to untar into
      file:
        path: /opt/myapp
        state: directory
```

Now, you untar the archive into the newly created directory.

```yaml
    - name: Untar archive into directory
      unarchive:
        src: /opt/deploy.tar.gz
        dest: /opt/myapp
```

Make the script executable.

```yaml
    - name: Make the script executable
      file:
        path: /opt/myapp/deploy/deployer.sh
        mode: '0755'
```

Execute the script and capture the output.

```yaml
    - name: Execute script and capture output
      shell: /opt/myapp/deploy/deployer.sh
      register: installer_output

    - name: Debug and show the variable installer_output
      debug:
        var: installer_output
```

Finally, run the playbook.

```bash
ansible-playbook -i /root/hosts /root/deploy.yml
```

```bash
ansible servers -i /root/hosts -m shell -a 'ls -l /opt/myapp'
```

## Create a playbook to deploy a jinja2 template

You can create .j2 templates to **stamp** values on each of the hosts as you execute the playbook.

```txt
This is an auto generated file by ansible at {{ ansible_date_time.data }} {{ ansible_date_time.time }}.

Hostname: {{ ansible_nodename }}
System: {{ ansible_os_family }}
Proc: {{ ansible_processor_count }}
```

Now let us copy this file to the hosts.

```yaml
---
- name: Start of Jinja2 Template Push
  hosts: servers
  vars:
  gather_facts: True
  become: False
  tasks:

    - name: Copy tempalte over to all hosts
      copy:
        src: /root/template.j2
        dest: "/root/template.txt"
```

Run the playbook

```bash
ansible-playbook -i /root/hosts /root/template.yml
```

The result is different depending on the host (the template is populated differently).

![Jinja2Template](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/6b2010a6-7ca3-42d9-aeba-c9155d3ad1d9)

**Note:** Jinja is a web template engine for the Python programming language.

## Create a playbook to deploy a jinja2 report

Create the .j2 template.

```
This is a system Validation at {{ ansible_date_time.time }} on {{ ansible_date_time.date }}

Unreachable systems:
----------------------------------------------
{% for host in ansible_play_hosts_all %}
{% if host not in ansible_play_hosts %}
{{ host }}
{% endif  %}
{% endfor %}

Hosts who have been up longer than a day:
----------------------------------------------
{% for host in ansible_play_hosts_all %}
{% if hostvars[host].uptime is defined %}
{% if 'day' in hostvars[host].uptime.stdout %}
 {{ hostvars[host].ansible_hostname }} - has not rebooted today
{% endif %}
{% endif %}
{% endfor %}
```

Create the playbook.

```yaml
---
- name: Start of Jinja2 Template Push
  hosts: servers
  vars:
  gather_facts: True
  become: False
  tasks:

    - name: Get information for uptime on all systems
      shell: uptime
      register: uptime

    - name: Copy template over to all hosts
      template:
        src: /root/template.j2
        dest: "/root/report.{{ ansible_date_time.iso8601_basic_short }}.txt
      run_once: yes
      delegate_to: localhost
```

Run the playbook.

```bash
ansible-playbook -i /root/hosts /root/template.yml
```
