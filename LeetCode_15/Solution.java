class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        final int N = nums.length;
        List<List<Integer>> triplets = new ArrayList<>();

        if (N < 3)
            return triplets;
        
        Arrays.sort(nums);

        for (int i = 0; i < N - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int target = 0 - nums[i];

            int leftIndex = i + 1, rightIndex = N - 1;

            while (leftIndex < rightIndex)
            {
                int sum = nums[leftIndex] + nums[rightIndex];

                if (sum == target)
                {
                    triplets.add(new ArrayList<Integer>(Arrays.asList( nums[i], nums[leftIndex], nums[rightIndex] )));

                    leftIndex ++;
                    rightIndex --;

                    while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1])
                        leftIndex ++;
                    
                    while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1])
                        rightIndex --;
                }
                else if (sum < target)
                    leftIndex ++;
                else
                    rightIndex --;
            }
        }

        return triplets;
    }
}