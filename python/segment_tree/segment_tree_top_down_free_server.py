class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        """
        task: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests
        You have to find the smalles index, greate than given i which corresponding value is smaller than a given value (arrivale-time)
        so first search in [i, k-1]. if no success: search also in [0, i-1]

        Top-Down-segment-Tree:
        save in eache node: min time of kids, left and right border (which server are composed in this node)
        ask left node if its min is smaller than current arrival and if its most right index is greater than i


        time-complexity:
        n * 2*log_2(k)
        """

        tree = SegmentTree(0, k-1)
        handeld = [0] * k
        for i in range(len(arrival)):
            pos = i % k
            server = tree.query(pos, arrival[i])
            if server == -1:
                server = tree.query(0, arrival[i])

            if server != -1:
                handeld[server] += 1
                tree.update(server, arrival[i] + load[i])

        maxE = max(handeld)
        ret = []
        for i in range(len(handeld)):
            if handeld[i] == maxE:
                ret.append(i)
        return ret


class SegmentTree:
    def __init__(self, left_border, right_border):
        self.left_border = left_border
        self.right_border = right_border
        self.left = None
        self.right = None
        if left_border == right_border:
            self.min = left_border
        else:
            mid = (left_border + right_border) >> 1
            self.left = SegmentTree(left_border, mid)
            self.right = SegmentTree(mid + 1, right_border)
            self.recalc()


    def recalc(self):
        if self.left_border == self.right_border:
            return;
        self.min = min(self.left.min, self.right.min)


    def update(self, pos, val):
        # postorder recalculation of min
        if self.left_border == self.right_border: # kid
            self.min = val
        else:
            mid = (self.left_border + self.right_border) >> 1
            if pos <= mid:
                self.left.update(pos, val)
            else:
                self.right.update(pos, val)
        self.recalc()


    def query(self, pos, threshold): # threshold is the current arrival_time
        if pos > self.right_border or self.min > threshold:
            return -1 
        if self.left_border == self.right_border: # kid
            return self.left_border
        else:
            left_ans = self.left.query(pos, threshold)
            return left_ans if left_ans != -1 else self.right.query(pos, threshold)

