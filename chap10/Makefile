-include ../Makefile

calendar: ## run calendar
	$(call gcc,$(CURRENT_DIR)/calendar.c)
	$(call exec)

strtime: ## run strtime
	$(call gcc,$(CURRENT_DIR)/strtime.c)
	$(call exec,"9:39:46pm 1 Feb 2011" "%I:%M:%s%p %d %b %Y")
	$(call exec,"9:39:46pm 1 Feb 2011" "%I:%M:%s%p %d %b %Y" "%F %T")

show: ## run show
	$(call gcc,$(CURRENT_DIR)/show.c)
	$(call exec)
