import java.util.ArrayList;
import java.util.List;

public class Subsets {
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), nums, 0);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> currentSubset, int[] nums, int start) {
        result.add(new ArrayList<>(currentSubset));

        for (int i = start; i < nums.length; i++) {
            currentSubset.add(nums[i]);
            backtrack(result, currentSubset, nums, i + 1);
            currentSubset.remove(currentSubset.size() - 1);
        }
    }

    public static void main(String[] args) {
        Subsets solution = new Subsets();
        
        int[] nums1 = {1, 2, 3};
        System.out.println("Subsets for [1, 2, 3]:");
        System.out.println(solution.subsets(nums1));

        int[] nums2 = {0};
        System.out.println("\nSubsets for [0]:");
        System.out.println(solution.subsets(nums2));
    }
}
