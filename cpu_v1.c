#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/smp.h>


static int __init cpu_enum_init(void) {
	int cpu;

	printk(KERN_INFO "Total num of online CPU's %d", num_online_cpus());

	for_each_online_cpu(cpu) {
		printk(KERN_INFO "FOUND CPU ID = %d\n", cpu);
	}

	printk(KERN_INFO "currently running on CPU's %d", smp_processor_id());

	return 0;
}

static void __exit cpu_enum_exit(void) {
	printk(KERN_INFO "Cpu v1 modules unloaded\n");
}

module_init(cpu_enum_init);
module_exit(cpu_enum_exit);
MODULE_LICENSE("GPL");
