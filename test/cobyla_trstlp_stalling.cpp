#include "nlopt.h"
#include "cobyla.h"

#include<iostream>
#include<cassert>
#include<cmath>
#include<vector>

int main(void)
{

  int n = 5;
  int m = 31;

  std::vector<unsigned long long> wv_ull{13939091300792589472ull, 13951285967439414441ull, 13942268766685165001ull, 4528087404883476480ull, 13930385619357824104ull, 13928497343869221837ull, 13928217434800784435ull, 13928497343869221837ull, 13928217434800784435ull, 13928489056048557184ull, 13928225722621449088ull, 13928357389549751501ull, 0ull, 0ull, 13904293202971590656ull, 13928359326794743515ull, 13928355451875262757ull, 9223372036854775808ull, 9223372036854775808ull, 0ull, 0ull, 13980898185170649090ull, 9223372036854775808ull, 13995730189812760576ull, 9223372036854775808ull, 13939068784520852258ull, 13936198822491068864ull, 13943149500888653134ull, 13929648255361029536ull, 13973214083726435811ull, 13973210299625380383ull, 13880096981059558151ull, 4680357504585826304ull, 0ull, 0ull, 13903364220840090072ull, 13919318121415303213ull, 4673774027458814734ull, 13903729541440484356ull, 13902616561965315497ull, 13758594853785459885ull, 4514333024565021461ull, 4519608699269603657ull, 13916147929413132329ull, 13916147929413278248ull, 13922712258845230224ull, 13936685751869670651ull, 4695959255396770943ull, 13746466546887058958ull, 0ull, 13908210402562605271ull, 4692665992841877258ull, 13917776065147765930ull, 4521116259434445680ull, 13756404163362498344ull, 13914824804147215462ull, 13928231663871746093ull, 4688346698717586835ull, 4763634069223243777ull, 4772358152957984768ull, 4724015968245578130ull, 4723497979454037326ull, 4695997051054201731ull, 13761352455798998849ull, 13767556342565410410ull, 4530652814720886561ull, 4509830977340970096ull, 13760527237285875863ull, 4539712854269998058ull, 4544184305710825289ull, 13755144515998968820ull, 13734741433106521636ull, 4538768332615749794ull, 4536512825418010592ull, 13615173092680853920ull, 4379442010155724661ull, 13741341816994710345ull, 13751146834959316246ull, 13747658596908352062ull, 4376688539753921072ull, 13587829963511842826ull, 4499218745353218616ull, 4512785631276614173ull, 13752943147145110774ull, 4384905435583558906ull, 13596125950413637063ull, 13741138829533413304ull, 4519905196987031569ull, 4715719256081550477ull, 4727913937681293077ull, 4718896949889799224ull, 13751459441738252288ull, 4707013582503048296ull, 4705125142771609318ull, 4704845562188845338ull, 4705125142771609318ull, 4704845562188845338ull, 4705115094475664416ull, 4704855610484790240ull, 4704985352694975693ull, 9223372036854775808ull, 9223372036854775808ull, 4680921166116814848ull, 4704987352790073199ull, 4704983352170381457ull, 0ull, 0ull, 9223372036854775808ull, 9223372036854775808ull, 4757526148315873282ull, 0ull, 4772358152957984768ull, 0ull, 4715676217311487624ull, 4712867846345470708ull, 4719541928818854809ull, 4707238577564733864ull, 4749842108248716147ull, 4749838201393548431ull, 4657589563713477877ull, 4528087404883476480ull, 4715719263937813663ull, 4727913930584638635ull, 4718896729830389188ull, 13751459441738252288ull, 4707013582503048296ull, 4705125307014445996ull, 4704845397946008660ull, 4705125307014445996ull, 4704845397946008660ull, 4705117019193781378ull, 4704853685766673278ull, 4704985352694975693ull, 9223372036854775808ull, 9223372036854775808ull, 4680921166116814848ull, 4704987289939967710ull, 4704983415020486946ull, 13903729541440602112ull, 13902616561964810240ull, 4680357504585826304ull, 4679244525110034432ull, 4757526105430349484ull, 4680357504585826304ull, 4772358148658714234ull, 4679244525110034432ull, 4715696747666072264ull, 4712826785636301428ull, 4719777464033877414ull, 4706276218506253016ull, 4749842046871660006ull, 4749838262770604572ull, 4656724854167421175ull, 4680357504585826304ull, 4715719022936460411ull, 4727914093794512422ull, 4718899844044453656ull, 13751459441738252288ull, 4707013582503048296ull, 4705122012309310830ull, 4704848692651143826ull, 4705122012309310830ull, 4704848692651143826ull, 4705088810776130470ull, 4704881894184324186ull, 4704985352694975693ull, 9223372036854775808ull, 9223372036854775808ull, 4680921166116814848ull, 4704989217950793728ull, 4704981487009660928ull, 13916147929413156864ull, 13916147929413189632ull, 4692775892558381056ull, 4692775892558413824ull, 4757525871907153452ull, 4692775892558381056ull, 4772358118406894789ull, 4692775892558413824ull, 4715284909524176606ull, 4713650461920092744ull, 4716256466377111581ull, 4715420814318766054ull, 4749843929694732289ull, 4749836379947532289ull, 4665809566328984709ull, 4692775892558413824ull, 4715719456338319923ull, 4727913893418795018ull, 4718896546681064013ull, 13751459441738252288ull, 4707013582503048296ull, 4705124957117391661ull, 4704845747843062995ull, 4705124957117391661ull, 4704845747843062995ull, 4705118134491328446ull, 4704852570469126210ull, 4704985352694975693ull, 9223372036854775808ull, 9223372036854775808ull, 4680921166116814848ull, 4704985750735917631ull, 4704984954224537025ull, 13749489662362124288ull, 0ull, 4526117625507348480ull, 9223372036854775808ull, 4757526148315873280ull, 4526117625507348480ull, 4772358152957984768ull, 0ull, 4715653010534280480ull, 4712914259899884996ull, 4719847170130569212ull, 4705175528863268960ull, 4749840543742704850ull, 4749839765899559728ull, 4656772833394008950ull, 4528087404883476480ull, 4715719192014590972ull, 4727913978679330350ull, 4718897560026803712ull, 13751459441738252288ull, 4707013582503048296ull, 4705124343370092639ull, 4704846361590362017ull, 4705124343370092639ull, 4704846361590362017ull, 4705109413978111833ull, 4704861290982342823ull, 4704985352694975693ull, 9223372036854775808ull, 9223372036854775808ull, 4680921166116814848ull, 4704987865325749241ull, 4704982839634705415ull, 0ull, 0ull, 9223372036854775808ull, 9223372036854775808ull, 4757526148315873282ull, 0ull, 4772358152957984768ull, 0ull, 4715576292121902642ull, 4713067696724640672ull, 4718831866624781973ull, 4710078826341025208ull, 4749842608771837282ull, 4749837700870427296ull, 4660296911634947926ull, 4528087404883476480ull, 4715719263937813664ull, 4727913930584638633ull, 4718896729830389193ull, 13751459441738252288ull, 4707013582503048296ull, 4705125307014446029ull, 4704845397946008627ull, 4705125307014446029ull, 4704845397946008627ull, 4705117019193781376ull, 4704853685766673280ull, 4704985352694975693ull, 9223372036854775808ull, 9223372036854775808ull, 4680921166116814848ull, 4704987289939967707ull, 4704983415020486949ull, 0ull, 0ull, 9223372036854775808ull, 9223372036854775808ull, 4757526148315873282ull, 0ull, 4772358152957984768ull, 0ull, 4715696747666076450ull, 4712826785636293056ull, 4719777464033877326ull, 4706276218506253728ull, 4749842046871660003ull, 4749838262770604575ull, 4656724944204782343ull, 4528087404883476480ull, 4416771228484763648ull, 13640701817246449664ull, 13628074956993593344ull, 4392848982200549376ull, 13785626545772085600ull, 13650590910726012928ull, 4427414501041635328ull, 13785626545772204540ull, 13611050428186755072ull, 4562254508917290902ull, 4415319838776360960ull, 13638810622886936576ull, 4562254508917308528ull, 13785626545772135087ull, 4394011303430062080ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 13623628016574791680ull, 4400343940650237952ull, 4562254508917347738ull, 4379684117164326912ull, 4386121207989141504ull, 4400255979720015872ull, 13623715977505013760ull, 13785626545772123546ull, 13603056154019102720ull, 13609493244843917312ull, 13623628016574791680ull, 4400343940650237952ull, 4562254508917347738ull, 4379684117164326912ull, 4386121207989141504ull, 4400255979720015872ull, 13623715977505013760ull, 13785626545772123546ull, 13603056154019102720ull, 13609493244843917312ull, 13624985363679281152ull, 4401798044777971712ull, 4388828205616726016ull, 4562254508917367520ull, 13604318943123603456ull, 4401613326824505344ull, 13625170081632747520ull, 13612200242471501824ull, 13785626545772143328ull, 4380946906268827648ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 4391454938895482880ull, 13614391569145659392ull, 13602781825867972608ull, 4366099101247340544ull, 4562254508917370436ull, 13614826975750258688ull, 4391019532290883584ull, 4379409789013196800ull, 13589471138102116352ull, 13785626545772146244ull, 4607182418800572821ull, 13682370399699710276ull, 4442765934076497508ull, 13650718697139745390ull, 13652769524888549152ull, 13692571200977371136ull, 4607182418803073008ull, 13677657870647629168ull, 4438731058059772872ull, 4446151927472169080ull, 13830554455655348629ull, 4458998362844934468ull, 13666137970931273316ull, 4427346660284969582ull, 4429397488033773344ull, 4469199164122595328ull, 13830554455657848816ull, 4454285833792853360ull, 13662103094914548680ull, 13669523964326944888ull, 4607182418800572821ull, 13682370399699710276ull, 4442765934076497508ull, 13650718697139745390ull, 13652769524888549152ull, 13830554455655348629ull, 4458998362844934468ull, 13666137970931273316ull, 4427346660284969582ull, 4429397488033773344ull, 13692571200977371136ull, 4607182418803073008ull, 13677657870647629168ull, 4438731058059772872ull, 4446151927472169080ull, 4469199164122595328ull, 13830554455657848816ull, 4454285833792853360ull, 13662103094914548680ull, 13669523964326944888ull, 4417749759473745920ull, 13641473640049410048ull, 4607182418800017048ull, 4392241089709342720ull, 4399946467196796928ull, 13641121796328521728ull, 4418101603194634240ull, 13830554455654792856ull, 13615613126564118528ull, 13623318504051572736ull, 4420283034264141824ull, 13645062446002470912ull, 13634084921910755328ull, 4607182418800017470ull, 4404661173056700416ull, 4418875659380588544ull, 13641966221258653696ull, 4402268635754659840ull, 13830554455654793237ull, 13621137072982065152ull, 4442665242714963968ull, 13667178572639371264ull, 13660602668471549952ull, 4425578282263511040ull, 4607182418800026722ull, 13666037279569739776ull, 4443806535784595456ull, 4437230631616774144ull, 13648950319118286848ull, 13830554455654802530ull, 13791428228840047952ull, 4569513778748746304ull, 4559158637304981696ull, 4555799148290612780ull, 4550160862008715920ull, 4671813033333085191ull, 4667521577000970987ull, 4680332475782681534ull, 4693412711836232644ull, 4673406567394997511ull, 4695978153225486337ull, 4681941948662587216ull, 4713389244994036226ull, 4695978153225486336ull, 4704941997744839355ull, 4689855297832521751ull, 4547762212671443811ull, 4551828872613824951ull, 4688696828120212408ull, 4686051502982096887ull, 13903729541440484356ull, 13902616561965315497ull, 13758594853785459885ull, 4514333024565021461ull, 4519608699269603657ull, 4645624572261175152ull, 13809433546392076288ull, 4663636654136605574ull, 4626823033903134592ull, 4654858750306683038ull, 4445096989663058651ull, 4607182418800017409ull, 4451796164945117184ull, 4415445183101927424ull, 4458657598538776576ull, 13664931677136095507ull, 4457482463274336256ull, 13819062610988524131ull, 4603372882837350452ull, 13828720467182329716ull, 13663974018719926547ull, 4454250341470306304ull, 4598348019624530359ull, 13828329771337627383ull, 13826993351421454921ull, 0ull, 13675077352843974841ull, 4606719426826863554ull, 4599367732921842066ull, 4578922311145119364ull, 4607182418800060690ull, 4607182418800927118ull, 4560025048604039290ull, 13778346708543356775ull, 13729115419207648767ull, 4698307194643984816ull, 4693399092821624229ull, 4742843146475182888ull, 0ull, 4707013582503054184ull, 4705124957117403431ull, 4704845747843074775ull, 4705124957117403431ull, 4704845747843074775ull, 4705118134491340230ull, 4704852570469137976ull, 4704985352694987468ull, 4528087404883476480ull, 4528087404883476480ull, 4680921166117191648ull, 4704985750735929404ull, 4704984954224548802ull, 4532590977669988290ull, 4718896546681065481ull, 4727913893418795390ull, 4532590982078591080ull, 4757526148315873288ull, 4452089002274062336ull, 4772358152957984768ull, 4532590982078591080ull, 4715653010534281939ull, 4712914259899887967ull, 4719847170130569933ull, 4705175528863280830ull, 4749840543742704846ull, 4749839765899559754ull, 4715719456338321382ull, 13711666419859793411ull, 4504279962926125261ull, 13866108065092123739ull, 4650010166804568631ull, 13875778413275494850ull, 13746466546887058958ull, 4546026805549083739ull, 13908210402562605271ull, 4692665992841877258ull, 13917776065147765930ull, 4698307194643984816ull, 4693399092821624229ull, 4742843146475182888ull, 0ull, 4707013582503054184ull, 4705124957117403431ull, 4704845747843074775ull, 4705124957117403431ull, 4704845747843074775ull, 4705118134491340230ull, 4704852570469137976ull, 4704985352694987468ull, 4528087404883476480ull, 4528087404883476480ull, 4680921166117191648ull, 4704985750735929404ull, 4704984954224548802ull, 4532590977669988290ull, 4718896546681065481ull, 4727913893418795390ull, 4532590982078591080ull, 4757526148315873288ull, 4452089002274062336ull, 4772358152957984768ull, 4532590982078591080ull, 4715653010534281939ull, 4712914259899887967ull, 4719847170130569933ull, 4705175528863280830ull, 4749840543742704846ull, 4749839765899559754ull, 4715719456338321382ull, 4576ull, 161ull, 93802101124671ull, 93824998641680ull, 98784247846ull, 34359738375ull, 42949672969ull, 51539607563ull, 60129542157ull, 68719476751ull, 12884901905ull, 21474836481ull, 81604378645ull, 103079215106ull, 111669149721ull, 120259084315ull, 128849018909ull, 137438953503ull, 146028888097ull, 154618822691ull, 25769803813ull, 177ull, 0ull, 140737339843586ull, 0ull, 0ull, 1ull, 1792ull, 0ull, 0ull, 0ull, 0ull, 512ull, 0ull, 0ull, 0ull, 5ull, 1024ull, 0ull, 0ull, 0ull, 5ull, 0ull, 177ull, 0ull, 140737339843589ull, 0ull, 0ull, 2ull, 1792ull, 0ull, 0ull, 0ull, 0ull, 512ull, 0ull, 0ull, 0ull, 5ull, 1024ull, 0ull, 0ull, 0ull, 5ull, 0ull, 97ull, 1ull, 140737339843589ull, 0ull, 0ull, 2ull, 768ull, 0ull, 0ull, 0ull, 0ull, 0ull, 129ull, 1ull, 140737339843586ull, 0ull, 0ull, 1ull, 512ull, 0ull, 0ull, 0ull, 0ull, 768ull, 0ull, 0ull, 0ull, 5ull, 177ull, 1ull, 140737339843586ull, 0ull, 0ull};
  
  std::vector<int> iactv{20, 19, 32, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 3, 2, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 1202590843, 1065646817, 49, 0, 1768846683, 825914228, 1868767276, 1869771886, 1881156716, 745431404, 1952669984, 1566930537, -134450688, 32767, 97, 0, 0, 0, -148511744, 32767, 0, 0, 0, 0, -134495998, 32767, 0, 0, 0, 256, -134495248};
  
  auto iact = iactv.data();
  auto w    = reinterpret_cast<double *>(wv_ull.data());
  
  auto a   = w + 286;
  auto con = w;

  unsigned long long rho_ull = 4695978153225486337;

  double rho = *reinterpret_cast<double *>(&rho_ull);

  auto dx = w + 461;
  int ifull = 1;
  auto iz     = w + 466;
  auto izdota = w + 491;
  auto ivmc = w + 496;
  auto isdirn = w + 528;
  auto idxnew = w + 533;
  auto ivdm = w + 538;

  auto rc = trstlp(&n, &m, a, con, &rho, dx, &ifull, iact, iz,izdota,ivmc,isdirn,idxnew,ivdm);

  assert(rc == NLOPT_SUCCESS);
  return 0;
}
