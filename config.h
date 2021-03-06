#define SCALE 22
#define OX 5
#define OY 5

/* Name  X  Y  W  H  VK */
struct btn_info buttons[] = {
	{_T("ESC"), 0, 1, 2, 2, VK_ESCAPE},
	{_T("F1"), 2, 0, 2, 2, VK_F1},
	{_T("F2"), 4, 0, 2, 2, VK_F2},
	{_T("F3"), 6, 0, 2, 2, VK_F3},
	{_T("F4"), 8, 0, 2, 2, VK_F4},
	{_T("F5"), 10, 0, 2, 2, VK_F5},
	{_T("F6"), 12, 0, 2, 2, VK_F6},
	{_T("F7"), 2, 2, 2, 2, VK_F7},
	{_T("F8"), 4, 2, 2, 2, VK_F8},
	{_T("F9"), 6, 2, 2, 2, VK_F9},
	{_T("F10"), 8, 2, 2, 2, VK_F10},
	{_T("F11"), 10, 2, 2, 2, VK_F11},
	{_T("F12"), 12, 2, 2, 2, VK_F12},
	{_T("7"), 6, 4, 2, 2, '7'},
	{_T("8"), 8, 4, 2, 2, '8'},
	{_T("9"), 10, 4, 2, 2, '9'},
	{_T("4"), 6, 6, 2, 2, '4'},
	{_T("5"), 8, 6, 2, 2, '5'},
	{_T("6"), 10, 6, 2, 2, '6'},
	{_T("1"), 6, 8, 2, 2, '1'},
	{_T("2"), 8, 8, 2, 2, '2'},
	{_T("3"), 10, 8, 2, 2, '3'},
	{_T("0"), 6, 10, 4, 2, '0'},
	{_T("."), 10, 10, 2, 2, VK_DECIMAL},
	{_T("<-"), 12, 4, 2, 2, VK_BACK},
	{_T("Enter"), 12, 6, 2, 6, VK_RETURN},
	{_T("<"), 0, 10, 2, 2, VK_LEFT},
	{_T(">"), 4, 10, 2, 2, VK_RIGHT},
	{_T("^"), 2, 8, 2, 2, VK_UP},
	{_T("_"), 2, 10, 2, 2, VK_DOWN},
	{_T("Home"), 1, 4, 2, 2, VK_HOME},
	{_T("End"), 1, 6, 2, 2, VK_END},
	{_T("PgUp"), 3, 4, 2, 2, VK_PRIOR},
	{_T("PgDn"), 3, 6, 2, 2, VK_NEXT},
	{NULL, 0, 0, 0, 0, 0},
};
