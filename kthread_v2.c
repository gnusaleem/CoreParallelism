#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

struct task_struct *task;

static int __init thread_init(void) {
	pid_t current_pid;

	//Current is macro which is used to display the current pid
	task = current;

	current_pid = task->pid;

	pr_info("Current PID = %d\n", current_pid);
	pr_info("Current comm = %s\n", current->comm);
	pr_info("Current parent pid = %d\n", current->parent->pid);

	return 0;
}

static void __exit thread_exit(void) {
	pr_info("Module unloaded\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saleemuddin Shaik");
MODULE_DESCRIPTION("Kthread_v3");

module_init(thread_init);
module_exit(thread_exit);
