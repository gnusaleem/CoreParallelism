# CoreParallelism
Linux Kernel Concepts

## CPU Related API

- num_online_cpus() -> Display's how many CPU's are there.
- for_each_online_cpu(int) -> Iterate over all the active CPU's.
- smp_processor_id() -> Display's current code is running in which CPU.

## task struct API

### for starting the process

- for_each_process(task struct) --> To display the running processes.
- pid_t pid -> to display the pid of task.
- *current* keyword -> it is a macro which display the current pid, name and parent pid ..etc.
- kthread_create() -> create a new thread, but it won't start the thread, to start the thread,
  we have to call wake_up_process(thread_ptr), to start the execution.
- kthread_run() -> creates the thread and start the thread immediately after creation.
- wake_up_process(thread_ptr) -> move the thread from sleeping state to running state, return type is int.

### for stopping the process

- kthread_stop(thread_ptr) -> to stop the current execution process.
- kthread_should_stop -> it is a loop, it will return the true, and thread breaks the loop, also this condition will be
used for running the process continously by using *!kthread_should_stop*, return 1 for running the thread continously,
return 0 to stop the loop.

```c
Both the API's are having same syntax, based on usage we can decide.

struct task_struct *kthread_create(thread_function, void *data, const char str[]);
struct task_struct *kthread_run(thread_function, void *data, const char str[]);

- int (*thread_function(void *data)) -> it will accept only single argument, it is a function pointer.
- void *data -> data to pass as argument.
- const char str -> name format string.
```