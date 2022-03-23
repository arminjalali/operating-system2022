#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
    static LIST_HEAD(birthday_list);
    struct birthday{
        int day;
        int month;
        int year;
        struct list_head list;
    };

    struct birthday *ptr;
	struct birthday *tmp;
    struct birthday *person;
    int i ;
    person = kmalloc(sizeof(*person), GFP_KERNEL);
    person -> day = 14;
    person -> month = 2;
    person -> year = 2001;
    INIT_LIST_HEAD(&person -> list);
    list_add_tail(&person -> list, &birthday_list);
  
   
    for(i = 1; i<6 ;i++){
		person = kmalloc(sizeof(person), GFP_KERNEL);
    	person->day = i+1;
   		person->month = i;
    	person->year = 2000 + i;
		list_add_tail(&person->list, &birthday_list);
	}

    list_for_each_entry(ptr, &birthday_list, list){
         printk(KERN_INFO "year: %d month: %d day: %d\n", ptr->year , ptr->month ,ptr->day);
    }

    list_for_each_entry_safe(ptr,tmp, &birthday_list, list){
        list_del(&ptr->list);
        kfree(ptr);
    }
    printk(KERN_INFO "Loading Module\n");
    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
    printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");