class Solution:
    def merge1(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        O(n+m)
        O(m+n)
        双指针
        """
        i = 0
        j = 0
        nums3 = []
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                nums3.append(nums1[i])
                i += 1
            else:
                nums3.append(nums2[j])
                j += 1
        while i < m:
            nums3.append(nums1[i])
            i += 1
        while j < n:
            nums3.append(nums2[j])
            j += 1
        nums1[:] = nums3

    def merge2(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        O(n+m)
        O(1)
        逆序指针
        """
        i = m-1
        j = n-1
        p = m + n - 1
        while i >= 0 and j >= 0:
            if nums1[i]<=nums2[j]:
                nums1[p] = nums1[i]
                i+=1
            else:
                nums1[p] = nums1[j]
                j+=1
            p-=1
        while i >= 0:
            nums1[p] = nums1[i]
            i-=1
            p-=1
        while j >= 0:
            nums1[p] = nums1[j]
            j -= 1
            p -= 1
