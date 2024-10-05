// segment tree implementation in GO

package main

import "fmt"

type SegmentTreeNode struct {
	Sum  int
	low  int
	high int

	left  *SegmentTreeNode
	right *SegmentTreeNode
}

func buildTree(nums []int, low, high int) *SegmentTreeNode {
	// create new node
	node := &SegmentTreeNode{low: low, high: high}
	// check for leaf node
	if low == high {
		node.Sum = nums[low]
		return node
	}
	mid := (low + high) / 2
	leftNode := buildTree(nums, low, mid)
	rightNode := buildTree(nums, mid+1, high)

	node.left = leftNode
	node.right = rightNode

	node.Sum = leftNode.Sum + rightNode.Sum
	return node
}

/*
	CASE1:
		Node interval is inside the query interval. eg [4,5]
	CASE2:
		Node interval is completely outside query interval.
		(node start index) > (query end index)
		node_interval = [0,1] , query = [3,4]
	CASE3:
		Partial overlap
		assume the query = [1,4],
		node_interval = [0,3] + node_interval = [2,4]
*/

func (s *SegmentTreeNode) RangeQuery(low, high int) int {
	// base case
	if low <= s.low && high >= s.high {
		return s.Sum
	}

	// out of range
	if low > s.high || high < s.low {
		return 0
	}

	return s.left.RangeQuery(low, high) + s.right.RangeQuery(low, high)
}

func main() {
	var nums []int = []int{1, 3, 5, 7, 9, 11}
	root := buildTree(nums, 0, len(nums)-1)

	fmt.Println(root.RangeQuery(1, 3)) // output: 15
}
