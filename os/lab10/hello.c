#include <stdlib.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("dual BSD/GPL");

static int hello_init(void)
{
   printk("<1> Hello world!\n");
   exit(0);
}

static int hello_exit(void)
{
   printk("<1> Hello world!\n");
   exit(0);
}

module_init(hello_init);
module_exit(hello_exit);
