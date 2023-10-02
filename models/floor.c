#include <psxgte.h>
#include "../display.h"

int floor_num_faces = 164;

SVECTOR floor_verts[] = {
  {-1582,1538,0},
  {-1978,1538,0},
  {-1978,1978,0},
  {-1582,1978,0},
  {1978,1538,0},
  {1582,1538,0},
  {1582,1978,0},
  {1978,1978,0},
  {1187,1538,0},
  {1187,1978,0},
  {791,1538,0},
  {791,1978,0},
  {396,1538,0},
  {396,1978,0},
  {0,1538,0},
  {0,1978,0},
  {-396,1538,0},
  {-396,1978,0},
  {-791,1538,0},
  {-791,1978,0},
  {-1187,1538,0},
  {-1187,1978,0},
  {-1187,-1978,0},
  {-1582,-1978,0},
  {-1582,-1538,0},
  {-1187,-1538,0},
  {-1582,-1099,0},
  {-1187,-1099,0},
  {-1582,-659,0},
  {-1187,-659,0},
  {-1582,-220,0},
  {-1187,-220,0},
  {-1582,220,0},
  {-1187,220,0},
  {-1582,659,0},
  {-1187,659,0},
  {-1582,1099,0},
  {-1187,1099,0},
  {-791,-1978,0},
  {-791,-1538,0},
  {-791,-1099,0},
  {-791,-659,0},
  {-791,-220,0},
  {-791,220,0},
  {-791,659,0},
  {-791,1099,0},
  {-396,-1978,0},
  {-396,-1538,0},
  {-396,-1099,0},
  {-396,-659,0},
  {-396,-220,0},
  {-396,220,0},
  {-396,659,0},
  {-396,1099,0},
  {0,-1978,0},
  {0,-1538,0},
  {0,-1099,0},
  {0,-659,0},
  {0,-220,0},
  {0,220,0},
  {0,659,0},
  {0,1099,0},
  {396,-1978,0},
  {396,-1538,0},
  {396,-1099,0},
  {396,-659,0},
  {396,-220,0},
  {396,220,0},
  {396,659,0},
  {396,1099,0},
  {791,-1978,0},
  {791,-1538,0},
  {791,-1099,0},
  {791,-659,0},
  {791,-220,0},
  {791,220,0},
  {791,659,0},
  {791,1099,0},
  {1187,-1978,0},
  {1187,-1538,0},
  {1187,-1099,0},
  {1187,-659,0},
  {1187,-220,0},
  {1187,220,0},
  {1187,659,0},
  {1187,1099,0},
  {1582,-1978,0},
  {1582,-1538,0},
  {1582,-1099,0},
  {1582,-659,0},
  {1582,-220,0},
  {1582,220,0},
  {1582,659,0},
  {1582,1099,0},
  {1978,-1978,0},
  {1978,-1538,0},
  {1978,-1099,0},
  {1978,-659,0},
  {1978,-220,0},
  {1978,220,0},
  {1978,659,0},
  {1978,1099,0},
  {-1978,-1978,0},
  {-1978,-1538,0},
  {-1978,-1099,0},
  {-1978,-659,0},
  {-1978,-220,0},
  {-1978,220,0},
  {-1978,659,0},
  {-1978,1099,0},
  {-1978,1538,-1979},
  {-1978,1978,-1979},
  {-1582,1978,-1979},
  {1978,1538,-1979},
  {1582,1978,-1979},
  {1978,1978,-1979},
  {1187,1978,-1979},
  {791,1978,-1979},
  {396,1978,-1979},
  {0,1978,-1979},
  {-396,1978,-1979},
  {-791,1978,-1979},
  {-1187,1978,-1979},
  {-1187,-1978,-1979},
  {-1582,-1978,-1979},
  {-791,-1978,-1979},
  {-396,-1978,-1979},
  {0,-1978,-1979},
  {396,-1978,-1979},
  {791,-1978,-1979},
  {1187,-1978,-1979},
  {1582,-1978,-1979},
  {1978,-1978,-1979},
  {1978,-1538,-1979},
  {1978,-1099,-1979},
  {1978,-659,-1979},
  {1978,-220,-1979},
  {1978,220,-1979},
  {1978,659,-1979},
  {1978,1099,-1979},
  {-1978,-1978,-1979},
  {-1978,-1538,-1979},
  {-1978,-1099,-1979},
  {-1978,-659,-1979},
  {-1978,-220,-1979},
  {-1978,220,-1979},
  {-1978,659,-1979},
  {-1978,1099,-1979},
  {-1582,1978,-990},
  {-1978,1978,-990},
  {-1978,-1538,-990},
  {-1978,-1978,-990},
  {-1978,1538,-990},
  {-1978,1099,-990},
  {0,-1978,-990},
  {396,-1978,-990},
  {-1978,-659,-990},
  {-1978,-1099,-990},
  {-1187,1978,-990},
  {791,-1978,-990},
  {1187,-1978,-990},
  {1978,-1538,-990},
  {1978,-1099,-990},
  {-1978,220,-990},
  {-1978,-220,-990},
  {1978,1538,-990},
  {1978,1978,-990},
  {1582,1978,-990},
  {1187,1978,-990},
  {-1582,-1978,-990},
  {-1187,-1978,-990},
  {791,1978,-990},
  {-396,-1978,-990},
  {-1978,659,-990},
  {-791,-1978,-990},
  {1978,-1978,-990},
  {396,1978,-990},
  {1582,-1978,-990},
  {1978,659,-990},
  {1978,1099,-990},
  {1978,220,-990},
  {0,1978,-990},
  {1978,-659,-990},
  {-396,1978,-990},
  {-791,1978,-990},
  {1978,-220,-990}
};

SVECTOR floor_norms[] = {
  {0.0,0.0,1.0},
  {-0.71,0.0,0.71},
  {-0.58,-0.58,0.58},
  {0.0,-0.71,0.71},
  {0.71,0.0,0.71},
  {0.58,-0.58,0.58},
  {0.0,0.71,0.71},
  {0.58,0.58,0.58},
  {-0.58,0.58,0.58},
  {0.0,-1.0,0.0},
  {-0.71,-0.71,0.0},
  {-1.0,-0.0,-0.0},
  {-0.71,0.71,0.0},
  {0.0,1.0,0.0},
  {1.0,-0.0,-0.0},
  {0.71,-0.71,0.0},
  {0.71,0.71,0.0}
};

INDEX floor_vertex_indices[] = {
  {3,2,0,1},
  {7,6,4,5},
  {6,9,5,8},
  {9,11,8,10},
  {11,13,10,12},
  {13,15,12,14},
  {15,17,14,16},
  {17,19,16,18},
  {19,21,18,20},
  {21,3,20,0},
  {25,24,22,23},
  {27,26,25,24},
  {29,28,27,26},
  {31,30,29,28},
  {33,32,31,30},
  {35,34,33,32},
  {37,36,35,34},
  {20,0,37,36},
  {39,25,38,22},
  {40,27,39,25},
  {41,29,40,27},
  {42,31,41,29},
  {43,33,42,31},
  {44,35,43,33},
  {45,37,44,35},
  {18,20,45,37},
  {47,39,46,38},
  {48,40,47,39},
  {49,41,48,40},
  {50,42,49,41},
  {51,43,50,42},
  {52,44,51,43},
  {53,45,52,44},
  {16,18,53,45},
  {55,47,54,46},
  {56,48,55,47},
  {57,49,56,48},
  {58,50,57,49},
  {59,51,58,50},
  {60,52,59,51},
  {61,53,60,52},
  {14,16,61,53},
  {63,55,62,54},
  {64,56,63,55},
  {65,57,64,56},
  {66,58,65,57},
  {67,59,66,58},
  {68,60,67,59},
  {69,61,68,60},
  {12,14,69,61},
  {71,63,70,62},
  {72,64,71,63},
  {73,65,72,64},
  {74,66,73,65},
  {75,67,74,66},
  {76,68,75,67},
  {77,69,76,68},
  {10,12,77,69},
  {79,71,78,70},
  {80,72,79,71},
  {81,73,80,72},
  {82,74,81,73},
  {83,75,82,74},
  {84,76,83,75},
  {85,77,84,76},
  {8,10,85,77},
  {87,79,86,78},
  {88,80,87,79},
  {89,81,88,80},
  {90,82,89,81},
  {91,83,90,82},
  {92,84,91,83},
  {93,85,92,84},
  {5,8,93,85},
  {95,87,94,86},
  {96,88,95,87},
  {97,89,96,88},
  {98,90,97,89},
  {99,91,98,90},
  {100,92,99,91},
  {101,93,100,92},
  {4,5,101,93},
  {24,103,23,102},
  {26,104,24,103},
  {28,105,26,104},
  {30,106,28,105},
  {32,107,30,106},
  {34,108,32,107},
  {36,109,34,108},
  {0,1,36,109},
  {112,111,148,149},
  {141,140,150,151},
  {110,147,152,153},
  {127,128,154,155},
  {143,142,156,157},
  {122,112,158,148},
  {111,110,149,152},
  {129,130,159,160},
  {133,134,161,162},
  {145,144,163,164},
  {113,115,165,166},
  {114,116,167,168},
  {124,123,169,170},
  {116,117,168,171},
  {126,127,172,154},
  {147,146,153,173},
  {123,125,170,174},
  {132,133,175,161},
  {117,118,171,176},
  {131,132,177,175},
  {138,139,178,179},
  {137,138,180,178},
  {118,119,176,181},
  {139,113,179,165},
  {128,129,155,159},
  {134,135,162,182},
  {119,120,181,183},
  {115,114,166,167},
  {140,124,151,169},
  {120,121,183,184},
  {136,137,185,180},
  {142,141,157,150},
  {130,131,160,177},
  {125,126,174,172},
  {144,143,164,156},
  {121,122,184,158},
  {135,136,182,185},
  {146,145,173,163},
  {173,163,108,107},
  {182,185,97,98},
  {184,158,19,21},
  {164,156,106,105},
  {174,172,38,46},
  {160,177,78,86},
  {157,150,104,103},
  {185,180,98,99},
  {183,184,17,19},
  {151,169,102,23},
  {166,167,7,6},
  {181,183,15,17},
  {162,182,96,97},
  {155,159,62,70},
  {179,165,101,4},
  {176,181,13,15},
  {180,178,99,100},
  {178,179,100,101},
  {177,175,86,94},
  {171,176,11,13},
  {175,161,94,95},
  {170,174,22,38},
  {153,173,109,108},
  {168,171,9,11},
  {169,170,23,22},
  {167,168,6,9},
  {165,166,4,7},
  {163,164,107,106},
  {161,162,95,96},
  {159,160,70,78},
  {149,152,2,1},
  {158,148,21,3},
  {156,157,105,104},
  {152,153,1,109},
  {150,151,103,102},
  {148,149,3,2}
};

INDEX floor_uv_indices[] = {
  {3,2,0,1},
  {7,6,4,5},
  {6,9,5,8},
  {9,11,8,10},
  {11,13,10,12},
  {13,15,12,14},
  {15,17,14,16},
  {17,19,16,18},
  {19,21,18,20},
  {21,3,20,0},
  {25,24,22,23},
  {27,26,25,24},
  {29,28,27,26},
  {31,30,29,28},
  {33,32,31,30},
  {35,34,33,32},
  {37,36,35,34},
  {20,0,37,36},
  {39,25,38,22},
  {40,27,39,25},
  {41,29,40,27},
  {42,31,41,29},
  {43,33,42,31},
  {44,35,43,33},
  {45,37,44,35},
  {18,20,45,37},
  {47,39,46,38},
  {48,40,47,39},
  {49,41,48,40},
  {50,42,49,41},
  {51,43,50,42},
  {52,44,51,43},
  {53,45,52,44},
  {16,18,53,45},
  {55,47,54,46},
  {56,48,55,47},
  {57,49,56,48},
  {58,50,57,49},
  {59,51,58,50},
  {60,52,59,51},
  {61,53,60,52},
  {14,16,61,53},
  {63,55,62,54},
  {64,56,63,55},
  {65,57,64,56},
  {66,58,65,57},
  {67,59,66,58},
  {68,60,67,59},
  {69,61,68,60},
  {12,14,69,61},
  {71,63,70,62},
  {72,64,71,63},
  {73,65,72,64},
  {74,66,73,65},
  {75,67,74,66},
  {76,68,75,67},
  {77,69,76,68},
  {10,12,77,69},
  {79,71,78,70},
  {80,72,79,71},
  {81,73,80,72},
  {82,74,81,73},
  {83,75,82,74},
  {84,76,83,75},
  {85,77,84,76},
  {8,10,85,77},
  {87,79,86,78},
  {88,80,87,79},
  {89,81,88,80},
  {90,82,89,81},
  {91,83,90,82},
  {92,84,91,83},
  {93,85,92,84},
  {5,8,93,85},
  {95,87,94,86},
  {96,88,95,87},
  {97,89,96,88},
  {98,90,97,89},
  {99,91,98,90},
  {100,92,99,91},
  {101,93,100,92},
  {4,5,101,93},
  {24,103,23,102},
  {26,104,24,103},
  {28,105,26,104},
  {30,106,28,105},
  {32,107,30,106},
  {34,108,32,107},
  {36,109,34,108},
  {0,1,36,109},
  {113,112,110,111},
  {117,116,114,115},
  {121,120,118,119},
  {125,124,122,123},
  {129,128,126,127},
  {131,113,130,110},
  {133,121,132,118},
  {137,136,134,135},
  {141,140,138,139},
  {145,144,142,143},
  {149,148,146,147},
  {153,152,150,151},
  {157,156,154,155},
  {152,159,151,158},
  {161,125,160,122},
  {120,163,119,162},
  {156,165,155,164},
  {167,141,166,138},
  {159,169,158,168},
  {173,172,170,171},
  {177,176,174,175},
  {179,177,178,174},
  {169,181,168,180},
  {176,149,175,146},
  {124,137,123,134},
  {140,183,139,182},
  {181,185,180,184},
  {187,153,186,150},
  {189,157,188,154},
  {185,191,184,190},
  {193,179,192,178},
  {128,117,127,114},
  {136,173,135,170},
  {165,161,164,160},
  {144,129,143,126},
  {191,131,190,130},
  {183,193,182,192},
  {163,145,162,142},
  {162,142,194,195},
  {182,192,196,197},
  {190,130,198,199},
  {143,126,200,201},
  {164,160,202,203},
  {135,170,204,205},
  {127,114,206,207},
  {192,178,197,208},
  {184,190,209,198},
  {188,154,210,211},
  {186,150,212,213},
  {180,184,214,209},
  {139,182,215,196},
  {123,134,216,217},
  {175,146,218,219},
  {168,180,220,214},
  {178,174,208,221},
  {174,175,221,218},
  {170,171,205,222},
  {158,168,223,220},
  {166,138,224,225},
  {155,164,226,202},
  {119,162,227,194},
  {151,158,228,223},
  {154,155,211,226},
  {150,151,213,228},
  {146,147,219,229},
  {142,143,195,200},
  {138,139,225,215},
  {134,135,217,204},
  {132,118,230,231},
  {130,110,199,232},
  {126,127,201,206},
  {118,119,231,227},
  {114,115,207,210},
  {110,111,232,233}
};

int floor_normal_indices[] = {
3,
7,
6,
9,
11,
13,
15,
17,
19,
21,
25,
27,
29,
31,
33,
35,
37,
20,
39,
40,
41,
42,
43,
44,
45,
18,
47,
48,
49,
50,
51,
52,
53,
16,
55,
56,
57,
58,
59,
60,
61,
14,
63,
64,
65,
66,
67,
68,
69,
12,
71,
72,
73,
74,
75,
76,
77,
10,
79,
80,
81,
82,
83,
84,
85,
8,
87,
88,
89,
90,
91,
92,
93,
5,
95,
96,
97,
98,
99,
100,
101,
4,
24,
26,
28,
30,
32,
34,
36,
0,
112,
141,
110,
127,
143,
122,
111,
129,
133,
145,
113,
114,
124,
116,
126,
147,
123,
132,
117,
131,
138,
137,
118,
139,
128,
134,
119,
115,
140,
120,
136,
142,
130,
125,
144,
121,
135,
146,
173,
182,
184,
164,
174,
160,
157,
185,
183,
151,
166,
181,
162,
155,
179,
176,
180,
178,
177,
171,
175,
170,
153,
168,
169,
167,
165,
163,
161,
159,
149,
158,
156,
152,
150,
148};

SVECTOR floor_uv[] = {
  {14,115},
  {14,127},
  {0,127},
  {0,115},
  {14,0},
  {14,13},
  {0,13},
  {0,0},
  {14,25},
  {0,25},
  {14,38},
  {0,38},
  {14,51},
  {0,51},
  {14,64},
  {0,64},
  {14,76},
  {0,76},
  {14,89},
  {0,89},
  {14,102},
  {0,102},
  {127,102},
  {127,115},
  {113,115},
  {113,102},
  {99,115},
  {99,102},
  {85,115},
  {85,102},
  {71,115},
  {71,102},
  {57,115},
  {57,102},
  {42,115},
  {42,102},
  {28,115},
  {28,102},
  {127,89},
  {113,89},
  {99,89},
  {85,89},
  {71,89},
  {57,89},
  {42,89},
  {28,89},
  {127,76},
  {113,76},
  {99,76},
  {85,76},
  {71,76},
  {57,76},
  {42,76},
  {28,76},
  {127,64},
  {113,64},
  {99,64},
  {85,64},
  {71,64},
  {57,64},
  {42,64},
  {28,64},
  {127,51},
  {113,51},
  {99,51},
  {85,51},
  {71,51},
  {57,51},
  {42,51},
  {28,51},
  {127,38},
  {113,38},
  {99,38},
  {85,38},
  {71,38},
  {57,38},
  {42,38},
  {28,38},
  {127,25},
  {113,25},
  {99,25},
  {85,25},
  {71,25},
  {57,25},
  {42,25},
  {28,25},
  {127,13},
  {113,13},
  {99,13},
  {85,13},
  {71,13},
  {57,13},
  {42,13},
  {28,13},
  {127,0},
  {113,0},
  {99,0},
  {85,0},
  {71,0},
  {57,0},
  {42,0},
  {28,0},
  {127,127},
  {113,127},
  {99,127},
  {85,127},
  {71,127},
  {57,127},
  {42,127},
  {28,127},
  {159,242},
  {159,255},
  {127,255},
  {127,242},
  {159,113},
  {159,127},
  {127,127},
  {127,113},
  {159,14},
  {159,28},
  {127,28},
  {127,14},
  {223,64},
  {223,51},
  {255,51},
  {255,64},
  {159,85},
  {159,99},
  {127,99},
  {127,85},
  {159,229},
  {127,229},
  {159,0},
  {127,0},
  {223,38},
  {223,25},
  {255,25},
  {255,38},
  {113,159},
  {99,159},
  {99,127},
  {113,127},
  {159,57},
  {159,71},
  {127,71},
  {127,57},
  {14,159},
  {0,159},
  {0,127},
  {14,127},
  {159,140},
  {159,153},
  {127,153},
  {127,140},
  {223,115},
  {223,102},
  {255,102},
  {255,115},
  {159,166},
  {127,166},
  {223,76},
  {255,76},
  {159,42},
  {127,42},
  {223,89},
  {255,89},
  {127,159},
  {127,127},
  {159,178},
  {127,178},
  {223,13},
  {223,0},
  {255,0},
  {255,13},
  {42,159},
  {28,159},
  {28,127},
  {42,127},
  {57,159},
  {57,127},
  {159,191},
  {127,191},
  {85,159},
  {85,127},
  {159,204},
  {127,204},
  {159,127},
  {127,127},
  {223,127},
  {255,127},
  {159,217},
  {127,217},
  {71,159},
  {71,127},
  {191,42},
  {191,57},
  {85,191},
  {71,191},
  {191,217},
  {191,229},
  {191,71},
  {191,85},
  {191,89},
  {191,76},
  {191,25},
  {191,13},
  {191,99},
  {191,113},
  {57,191},
  {191,204},
  {191,127},
  {191,115},
  {191,127},
  {191,140},
  {191,191},
  {99,191},
  {191,51},
  {191,38},
  {28,191},
  {14,191},
  {191,178},
  {42,191},
  {191,0},
  {191,166},
  {127,191},
  {113,191},
  {191,102},
  {191,28},
  {191,153},
  {0,191},
  {191,0},
  {191,14},
  {191,242},
  {191,255}
};
