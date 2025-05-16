class CountIntervals(object):

    def __init__(self):
        self.sl = SortedList()
        self.cnt = 0

    def add(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: None
        """
        if len(self.sl) and self.sl[-1][1] < left:
            self.sl.add((left, right))
            self.cnt += right - left + 1
            return
        i = 0
        while i < len(self.sl) and self.sl[i][1] < left:
            i += 1
        to_remove = []
        l = left
        r = right
        if i < len(self.sl):
            if self.sl[i][0] <= left and right <= self.sl[i][1]:
                return
            l = min(left, self.sl[i][0])
        while i < len(self.sl) and self.sl[i][0] <= r:
            interval = self.sl[i]
            size = interval[1] - interval[0] + 1
            self.cnt -= size
            to_remove.append(interval)
            r = max(right, interval[1])
            self.sl.pop(i)
            # i += 1

        # for interval in to_remove:
        #     self.sl.remove(interval)

        self.sl.add((l, r))
        self.cnt += r - l + 1
        

    def count(self):
        """
        :rtype: int
        """
        return self.cnt
        


# Your CountIntervals object will be instantiated and called as such:
# obj = CountIntervals()
# obj.add(left,right)
# param_2 = obj.count()