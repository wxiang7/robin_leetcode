class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char *head = 0, *oneedle = needle;
        if (*haystack == *needle && *needle == 0)
            return haystack;
        for (; *haystack != 0; ++haystack) {
            head = haystack;
            needle = oneedle;
            while (*head != 0 && *needle != 0 && *head == *needle) {
                ++head;
                ++needle;
            }
            if (*needle == 0) {
                return haystack;
            } else if (*head == 0) {
                return NULL;
            }
        }
        return NULL;
    }
};
