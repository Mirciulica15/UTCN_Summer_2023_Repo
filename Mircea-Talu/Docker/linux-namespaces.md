# Linux namespaces - what is their part in Linux containers?

They provide **isolation** of your processes.

You don't allow the child process to see the parent.

![ChildProcessIsolation](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/f1d810e0-ebef-410e-9a37-02edaedd5cc3)

But these processes can use as many **resources** as they want! Namespaces don't solve that problem, they only isolate the processes -> we need something else, control groups (**cgroups**).
