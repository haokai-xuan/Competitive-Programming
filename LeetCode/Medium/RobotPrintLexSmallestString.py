class Solution:
    def robotWithString(self, s: str) -> str:
        s_lst = deque(s)
        t_lst = deque()

        parts = []
        while s_lst or t_lst:
            char = min(s_lst)
            pos = len(s_lst) - 1
            rest_min = "{"
            while s_lst[pos] != char:
                rest_min = min(rest_min, s_lst[pos])
                pos -= 1
            for i in range(pos + 1):
                if s_lst[0] == char:
                    parts.append(s_lst.popleft())
                else:
                    t_lst.append(s_lst.popleft())

            while t_lst and t_lst[-1] <= rest_min:
                parts.append(t_lst.pop())

        return "".join(parts)
            