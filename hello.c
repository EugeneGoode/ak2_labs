#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/ktime.h>
#include <linux/slab.h>
#include <asm-generic/bug.h>

MODULE_AUTHOR("Zhenya Hudenko <zhenyahudenko@gmail.com>");
MODULE_DESCRIPTION("Lab 6");
MODULE_LICENSE("Dual BSD/GPL");

static uint counter = 1;

module_param(counter, uint, 0444);
MODULE_PARM_DESC(counter, "the number of hello world");

struct my_struct {
	struct list_head tlist;
	ktime_t time;
};

static LIST_HEAD(my_list_head);

static int __init hello_init(void)
{	
	if (counter == 0) {
		pr_warn("you cannot enter 0");
	} else if (counter >= 5 && counter <= 10) {
		pr_warn("The parameter is between 5 and 10");
	}

	BUG_ON((counter > 10));

	int i;
	for (i = 0; i <= counter; i++) {

		struct my_struct *ms = NULL;

		if (i != counter)
		{
			ms = kmalloc(sizeof(struct my_struct), GFP_KERNEL);
		}
		ms->time = ktime_get();
		list_add_tail(&ms->tlist, &my_list_head);

		pr_info("Hello, world!\n");
	}

	return 0;
}

static void __exit hello_exit(void)
{
	int counter = 0;
	struct my_struct *t, *tmp;

	list_for_each_entry_safe(t, tmp, &my_list_head, tlist) {
		pr_info("i: %d; ktime = %lld\n", counter++, ktime_to_ns(t->time));
		list_del(&t->tlist);
		kfree(t);
	}
	pr_info("Module removed\n");
}

module_init(hello_init);
module_exit(hello_exit);
