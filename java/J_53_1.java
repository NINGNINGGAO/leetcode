public class J_53_1 {
    class Status {
        int lSum;//表示 [l, r] 内以 l 为左端点的最大子段和
        int rSum;//表示 [l, r] 内以 r 为左端点的最大子段和
        int mSum;//表示 [l, r] 内的最大子段和
        int iSum;//表示 [l, r] 的区间和
        public Status(int lSum, int rSum, int mSum, int iSum) {
            this.lSum = lSum;
            this.rSum = rSum;
            this.mSum = mSum;
            this.iSum = iSum;
        }
    }
    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = Math.max(l.lSum, l.iSum + r.lSum);
        int rSum = Math.max(r.rSum, l.rSum + r.iSum);
        int mSum = Math.max(Math.max(l.mSum, r.mSum), l.rSum + r.lSum);
        return new Status(lSum, rSum, mSum, iSum);
    }

    Status get(int[] nums, int l, int r) {
        if (l == r) return new Status(nums[l], nums[l], nums[l], nums[l]);
        int m = (l + r) >> 1;
        Status lSub = get(nums, l, m);
        Status rSub = get(nums, m + 1, r);
        return pushUp(lSub, rSub);
    }

    public int maxSubArray(int[] nums) {
        return get(nums, 0, nums.length - 1).mSum;
    }
}