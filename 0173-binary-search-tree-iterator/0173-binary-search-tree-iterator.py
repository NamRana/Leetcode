class BSTIterator:
    def __init__(self, root: TreeNode):
        self.stack = []
        self._push_left(root)

    def _push_left(self, node):
        # Push the path going left until null
        while node:
            self.stack.append(node)
            node = node.left

    def next(self) -> int:
        node = self.stack.pop()
        self._push_left(node.right)   # queue up the right subtree
        return node.val

    def hasNext(self) -> bool:
        return bool(self.stack)