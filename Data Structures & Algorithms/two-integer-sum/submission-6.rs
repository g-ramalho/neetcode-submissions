impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();

        for i in 0..nums.len() {
            let c = target - nums[i];
            if map.contains_key(&c) { return vec![map[&c] as i32, i as i32] }

            map.insert(nums[i], i);
        }

        vec![]
    }
}
