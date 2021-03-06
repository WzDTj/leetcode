/**
 * 面试题57 - II. 和为s的连续正数序列
 * https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 **/

package problems

// import (
//         "fmt"
// )

func FindContinuousSequence(target int) [][]int {
	var results [][]int

	// fmt.Println("target: ", target)
	start, end := 1, 2
	for start < end {
		sum := (start + end) * (end - start + 1) / 2
		// fmt.Println("start: ", start, "; end: ", end, "; sum: ", sum)

		switch {
		case sum < target:
			end++
		case sum > target:
			start++
		case sum == target:
			var result []int
			for i := start; i <= end; i++ {
				result = append(result, i)
			}
			results = append(results, result)
			start++
		}

	}

	return results
}
