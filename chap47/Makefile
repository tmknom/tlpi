-include ../Makefile

demo: ## run demo
	$(call gcc,$(CURRENT_DIR)/demo.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svsem_demo
	make run

mon: ## run mon
	$(call gcc,$(CURRENT_DIR)/mon.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svsem_mon
	make run

setall: ## run setall
	$(call gcc,$(CURRENT_DIR)/setall.c)
	cp $(PROJECT_ROOT)/bin/main $(PROJECT_ROOT)/bin/svsem_setall
	make run
