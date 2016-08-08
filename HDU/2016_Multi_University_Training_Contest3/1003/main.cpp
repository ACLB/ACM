#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int vis[1100][1100];

int SG[][2] ={{2,3},
{3,2},
{4,6},
{5,8},
{6,4},
{7,11},
{8,5},
{9,14},
{10,16},
{11,7},
{12,19},
{13,21},
{14,9},
{15,24},
{16,10},
{17,27},
{18,29},
{19,12},
{20,32},
{21,13},
{22,35},
{23,37},
{24,15},
{25,40},
{26,42},
{27,17},
{28,45},
{29,18},
{30,48},
{31,50},
{32,20},
{33,53},
{34,55},
{35,22},
{36,58},
{37,23},
{38,61},
{39,63},
{40,25},
{41,66},
{42,26},
{43,69},
{44,71},
{45,28},
{46,74},
{47,76},
{48,30},
{49,79},
{50,31},
{51,82},
{52,84},
{53,33},
{54,87},
{55,34},
{56,90},
{57,92},
{58,36},
{59,95},
{60,97},
{61,38},
{62,100},
{63,39},
{64,103},
{65,105},
{66,41},
{67,108},
{68,110},
{69,43},
{70,113},
{71,44},
{72,116},
{73,118},
{74,46},
{75,121},
{76,47},
{77,124},
{78,126},
{79,49},
{80,129},
{81,131},
{82,51},
{83,134},
{84,52},
{85,137},
{86,139},
{87,54},
{88,142},
{89,144},
{90,56},
{91,147},
{92,57},
{93,150},
{94,152},
{95,59},
{96,155},
{97,60},
{98,158},
{99,160},
{100,62},
{101,163},
{102,165},
{103,64},
{104,168},
{105,65},
{106,171},
{107,173},
{108,67},
{109,176},
{110,68},
{111,179},
{112,181},
{113,70},
{114,184},
{115,186},
{116,72},
{117,189},
{118,73},
{119,192},
{120,194},
{121,75},
{122,197},
{123,199},
{124,77},
{125,202},
{126,78},
{127,205},
{128,207},
{129,80},
{130,210},
{131,81},
{132,213},
{133,215},
{134,83},
{135,218},
{136,220},
{137,85},
{138,223},
{139,86},
{140,226},
{141,228},
{142,88},
{143,231},
{144,89},
{145,234},
{146,236},
{147,91},
{148,239},
{149,241},
{150,93},
{151,244},
{152,94},
{153,247},
{154,249},
{155,96},
{156,252},
{157,254},
{158,98},
{159,257},
{160,99},
{161,260},
{162,262},
{163,101},
{164,265},
{165,102},
{166,268},
{167,270},
{168,104},
{169,273},
{170,275},
{171,106},
{172,278},
{173,107},
{174,281},
{175,283},
{176,109},
{177,286},
{178,288},
{179,111},
{180,291},
{181,112},
{182,294},
{183,296},
{184,114},
{185,299},
{186,115},
{187,302},
{188,304},
{189,117},
{190,307},
{191,309},
{192,119},
{193,312},
{194,120},
{195,315},
{196,317},
{197,122},
{198,320},
{199,123},
{200,323},
{201,325},
{202,125},
{203,328},
{204,330},
{205,127},
{206,333},
{207,128},
{208,336},
{209,338},
{210,130},
{211,341},
{212,343},
{213,132},
{214,346},
{215,133},
{216,349},
{217,351},
{218,135},
{219,354},
{220,136},
{221,357},
{222,359},
{223,138},
{224,362},
{225,364},
{226,140},
{227,367},
{228,141},
{229,370},
{230,372},
{231,143},
{232,375},
{233,377},
{234,145},
{235,380},
{236,146},
{237,383},
{238,385},
{239,148},
{240,388},
{241,149},
{242,391},
{243,393},
{244,151},
{245,396},
{246,398},
{247,153},
{248,401},
{249,154},
{250,404},
{251,406},
{252,156},
{253,409},
{254,157},
{255,412},
{256,414},
{257,159},
{258,417},
{259,419},
{260,161},
{261,422},
{262,162},
{263,425},
{264,427},
{265,164},
{266,430},
{267,432},
{268,166},
{269,435},
{270,167},
{271,438},
{272,440},
{273,169},
{274,443},
{275,170},
{276,446},
{277,448},
{278,172},
{279,451},
{280,453},
{281,174},
{282,456},
{283,175},
{284,459},
{285,461},
{286,177},
{287,464},
{288,178},
{289,467},
{290,469},
{291,180},
{292,472},
{293,474},
{294,182},
{295,477},
{296,183},
{297,480},
{298,482},
{299,185},
{300,485},
{301,487},
{302,187},
{303,490},
{304,188},
{305,493},
{306,495},
{307,190},
{308,498},
{309,191},
{310,501},
{311,503},
{312,193},
{313,506},
{314,508},
{315,195},
{316,511},
{317,196},
{318,514},
{319,516},
{320,198},
{321,519},
{322,521},
{323,200},
{324,524},
{325,201},
{326,527},
{327,529},
{328,203},
{329,532},
{330,204},
{331,535},
{332,537},
{333,206},
{334,540},
{335,542},
{336,208},
{337,545},
{338,209},
{339,548},
{340,550},
{341,211},
{342,553},
{343,212},
{344,556},
{345,558},
{346,214},
{347,561},
{348,563},
{349,216},
{350,566},
{351,217},
{352,569},
{353,571},
{354,219},
{355,574},
{356,576},
{357,221},
{358,579},
{359,222},
{360,582},
{361,584},
{362,224},
{363,587},
{364,225},
{365,590},
{366,592},
{367,227},
{368,595},
{369,597},
{370,229},
{371,600},
{372,230},
{373,603},
{374,605},
{375,232},
{376,608},
{377,233},
{378,611},
{379,613},
{380,235},
{381,616},
{382,618},
{383,237},
{384,621},
{385,238},
{386,624},
{387,626},
{388,240},
{389,629},
{390,631},
{391,242},
{392,634},
{393,243},
{394,637},
{395,639},
{396,245},
{397,642},
{398,246},
{399,645},
{400,647},
{401,248},
{402,650},
{403,652},
{404,250},
{405,655},
{406,251},
{407,658},
{408,660},
{409,253},
{410,663},
{411,665},
{412,255},
{413,668},
{414,256},
{415,671},
{416,673},
{417,258},
{418,676},
{419,259},
{420,679},
{421,681},
{422,261},
{423,684},
{424,686},
{425,263},
{426,689},
{427,264},
{428,692},
{429,694},
{430,266},
{431,697},
{432,267},
{433,700},
{434,702},
{435,269},
{436,705},
{437,707},
{438,271},
{439,710},
{440,272},
{441,713},
{442,715},
{443,274},
{444,718},
{445,720},
{446,276},
{447,723},
{448,277},
{449,726},
{450,728},
{451,279},
{452,731},
{453,280},
{454,734},
{455,736},
{456,282},
{457,739},
{458,741},
{459,284},
{460,744},
{461,285},
{462,747},
{463,749},
{464,287},
{465,752},
{466,754},
{467,289},
{468,757},
{469,290},
{470,760},
{471,762},
{472,292},
{473,765},
{474,293},
{475,768},
{476,770},
{477,295},
{478,773},
{479,775},
{480,297},
{481,778},
{482,298},
{483,781},
{484,783},
{485,300},
{486,786},
{487,301},
{488,789},
{489,791},
{490,303},
{491,794},
{492,796},
{493,305},
{494,799},
{495,306},
{496,802},
{497,804},
{498,308},
{499,807},
{500,809},
{501,310},
{502,812},
{503,311},
{504,815},
{505,817},
{506,313},
{507,820},
{508,314},
{509,823},
{510,825},
{511,316},
{512,828},
{513,830},
{514,318},
{515,833},
{516,319},
{517,836},
{518,838},
{519,321},
{520,841},
{521,322},
{522,844},
{523,846},
{524,324},
{525,849},
{526,851},
{527,326},
{528,854},
{529,327},
{530,857},
{531,859},
{532,329},
{533,862},
{534,864},
{535,331},
{536,867},
{537,332},
{538,870},
{539,872},
{540,334},
{541,875},
{542,335},
{543,878},
{544,880},
{545,337},
{546,883},
{547,885},
{548,339},
{549,888},
{550,340},
{551,891},
{552,893},
{553,342},
{554,896},
{555,898},
{556,344},
{557,901},
{558,345},
{559,904},
{560,906},
{561,347},
{562,909},
{563,348},
{564,912},
{565,914},
{566,350},
{567,917},
{568,919},
{569,352},
{570,922},
{571,353},
{572,925},
{573,927},
{574,355},
{575,930},
{576,356},
{577,933},
{578,935},
{579,358},
{580,938},
{581,940},
{582,360},
{583,943},
{584,361},
{585,946},
{586,948},
{587,363},
{588,951},
{589,953},
{590,365},
{591,956},
{592,366},
{593,959},
{594,961},
{595,368},
{596,964},
{597,369},
{598,967},
{599,969},
{600,371},
{601,972},
{602,974},
{603,373},
{604,977},
{605,374},
{606,980},
{607,982},
{608,376},
{609,985},
{610,987},
{611,378},
{612,990},
{613,379},
{614,993},
{615,995},
{616,381},
{617,998},
{618,382},
{621,384},
{624,386},
{626,387},
{629,389},
{631,390},
{634,392},
{637,394},
{639,395},
{642,397},
{645,399},
{647,400},
{650,402},
{652,403},
{655,405},
{658,407},
{660,408},
{663,410},
{665,411},
{668,413},
{671,415},
{673,416},
{676,418},
{679,420},
{681,421},
{684,423},
{686,424},
{689,426},
{692,428},
{694,429},
{697,431},
{700,433},
{702,434},
{705,436},
{707,437},
{710,439},
{713,441},
{715,442},
{718,444},
{720,445},
{723,447},
{726,449},
{728,450},
{731,452},
{734,454},
{736,455},
{739,457},
{741,458},
{744,460},
{747,462},
{749,463},
{752,465},
{754,466},
{757,468},
{760,470},
{762,471},
{765,473},
{768,475},
{770,476},
{773,478},
{775,479},
{778,481},
{781,483},
{783,484},
{786,486},
{789,488},
{791,489},
{794,491},
{796,492},
{799,494},
{802,496},
{804,497},
{807,499},
{809,500},
{812,502},
{815,504},
{817,505},
{820,507},
{823,509},
{825,510},
{828,512},
{830,513},
{833,515},
{836,517},
{838,518},
{841,520},
{844,522},
{846,523},
{849,525},
{851,526},
{854,528},
{857,530},
{859,531},
{862,533},
{864,534},
{867,536},
{870,538},
{872,539},
{875,541},
{878,543},
{880,544},
{883,546},
{885,547},
{888,549},
{891,551},
{893,552},
{896,554},
{898,555},
{901,557},
{904,559},
{906,560},
{909,562},
{912,564},
{914,565},
{917,567},
{919,568},
{922,570},
{925,572},
{927,573},
{930,575},
{933,577},
{935,578},
{938,580},
{940,581},
{943,583},
{946,585},
{948,586},
{951,588},
{953,589},
{956,591},
{959,593},
{961,594},
{964,596},
{967,598},
{969,599},
{972,601},
{974,602},
{977,604},
{980,606},
{982,607},
{985,609},
{987,610},
{990,612},
{993,614},
{995,615},
{998,617}};

bool vist[1100][1100];

int main()
{

    freopen("1003.in","r",stdin);

    freopen("test.txt","w",stdout);

    int ty,n,m;

    int T;

    Init();

    for(int i = 0;i<762;i++)
    {
        vist[SG[i][0]][SG[i][1]] = true;
    }

    scanf("%d",&T);

    while(T-- && scanf("%d %d %d",&ty,&n,&m))
    {
        if(ty == 1)
        {
            if(n%2 ==0 || m%2 ==0)
            {
                printf("B\n");
            }
            else printf("G\n");
        }
        else if(ty ==4)
        {
            if(vist[n][m])
            {
                printf("G\n");
            }
            else printf("B\n");
        }
        else if(ty == 3)
        {
            if((n+m-2)%3!=0)
            {
                printf("D\n");
            }
            else
            {
                if(vis[n-1][m-1] == -1)
                {
                    printf("G\n");
                }
                else if(vis[n-1][m-1] == 0)
                {
                    printf("D\n");
                }
                else printf("B\n");
            }
        }
        else if(ty ==2)
        {
            if(n == m)
            {
                printf("G\n");
            }
            else printf("B\n");
        }
    }
    return 0;
}
