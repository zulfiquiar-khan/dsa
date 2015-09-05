.PHONY: clean All

All:
	@echo "----------Building project:[ BinaryTree - Debug ]----------"
	@cd "BinaryTree" && $(MAKE) -f  "BinaryTree.mk"
clean:
	@echo "----------Cleaning project:[ BinaryTree - Debug ]----------"
	@cd "BinaryTree" && $(MAKE) -f  "BinaryTree.mk" clean
