#include <linux/bpf.h>
#include <linux/kernel.h>

SEC("kprobe/do_fork")
int trace_do_fork(struct pt_regs *ctx) {
    bpf_printk("Entering do_fork\n");
    return 0;
}
