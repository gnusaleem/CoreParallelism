# CoreParallelism
Linux Kernel Concepts

##CPU Related API

- num_online_cpus() -> Display's how many CPU's are there.
- for_each_online_cpu(int) -> Iterate over all the active CPU's.
- smp_processor_id() -> Display's current code is running in which CPU.