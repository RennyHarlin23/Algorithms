def twoSum(nums, target):
    map = {}
    for i in range(len(nums)):
        b = target - nums[i]
        if b in map:
            return [map[b], i]
        map[nums[i]] = i
    
    return []


nums = [2,7,11,15]
target = 9
result = twoSum(nums, target)
print(result)  