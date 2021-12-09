#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/ktime.h>
#include <linux/slab.h>


MODULE_AUTHOR("Volodymyr Makotkin <makotk11n@ukr.net>");
MODULE_DESCRIPTION("lab-5 linux kernel module");
MODULE_LICENSE("Dual BSD/GPL");



struct head_list
{
    struct head_list* next;
    ktime_t start_time;
    ktime_t end_time;
};


static struct head_list* head;
static uint counter = 1;

module_param(counter, uint, 0444);
MODULE_PARM_DESC(counter, "the number of hello world");



static int __init hello_init(void)
{
    uint i = 0;
    struct head_list *this_var, *next_var;

    pr_info("Input %d\n", counter);
    if (!counter)
    {
        pr_info("You cannot enter 0");
        pr_info("");
        return 0;
    }

    if (counter >= 5 && counter <= 10)
    {
        pr_warn("You should enter number less than 5");
    }
    else
    {
        if (counter > 10)
        {
            pr_err("The parameter is greater than 10");
            pr_info("");
            return -EINVAL;
        }
    }

    head = kmalloc(sizeof(struct head_list *), GFP_KERNEL);
    this_var = head;

    for (i = 0; i < counter; i++)
    {
        this_var->next = kmalloc(sizeof(struct head_list), GFP_KERNEL);
        this_var->start_time = ktime_get();
        pr_info("Hello, world!\n");
        this_var->end_time = ktime_get();
        next_var = this_var;
        this_var = this_var->next;
    }

    kfree(next_var->next);
    next_var->next = NULL;

    return 0;
}



static void __exit hello_exit(void)
{
    struct head_list *tmp_var;

    while (head != NULL && counter != 0)
    {
        tmp_var = head;
        pr_info("Printing time: %lld",
                tmp_var->end_time - tmp_var->start_time);
        head = tmp_var->next;
        kfree(tmp_var);
    }

    pr_info("Module removed");
    pr_info("");
}



module_init(hello_init);
module_exit(hello_exit);
