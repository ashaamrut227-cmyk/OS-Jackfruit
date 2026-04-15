#ifndef MONITOR_IOCTL_H
#define MONITOR_IOCTL_H

#include <linux/ioctl.h>

#define MONITOR_MAGIC 0xCA

struct monitor_params {
    int pid;
    int soft_mib;
    int hard_mib;
};

#define MONITOR_REGISTER_PID   _IOW(MONITOR_MAGIC, 1, struct monitor_params)
#define MONITOR_UNREGISTER_PID _IOW(MONITOR_MAGIC, 2, struct monitor_params)

#endif