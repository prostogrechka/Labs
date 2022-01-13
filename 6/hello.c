#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/ktime.h>
#include <linux/slab.h>
#include <asm-generic/bug.h>

MODULE_AUTHOR("Igor Rallo");
MODULE_DESCRIPTION("LB 6");
MODULE_LICENSE("Dual BSD/GPL");

static uint numtimes = 1;

module_param(numtimes, uint, 0444);
MODULE_PARM_DESC(numtimes, "Number of prints");

struct my_struct {
	struct list_head tlist;
	ktime_t time;
};

static LIST_HEAD(my_list_head);

static int __init hello_init(void)
{	
	if (numtimes == 0) {
		pr_warn("The parameter equal 0");
	} else if (numtimes >= 5 && numtimes <= 10) {
		pr_warn("The parameter is in between 5 and 10");
	}

	BUG_ON((numtimes > 10));

	int i;
	for (i = 0; i <= numtimes; i++) {

		struct my_struct *ms = NULL;

		if (i != numtimes)
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
	int count = 0;
	struct my_struct *t, *tmp;

	list_for_each_entry_safe(t, tmp, &my_list_head, tlist) {
		pr_info("i: %d; ktime = %lld\n", count++, ktime_to_ns(t->time));
		list_del(&t->tlist);
		kfree(t);
	}
	pr_info("Module unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);
