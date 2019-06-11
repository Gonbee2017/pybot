//====================================================================
//Ragnarok Online TaekwonKid Jobchange Script
//
//　■ CHANGE_TK -> 0〜3
//     CHANGE_TK_LV -> BaseLevel保存変数
//====================================================================

//==========================================
// 試験申請および転職
//------------------------------------------

payon,157,141,5	script	鳳凰	753,{
	if(Job == Job_Taekwon) {
		mes "[鳳凰]";
		mes "修練を怠っていないか？";
		mes "テコンキッドになった後、";
		mes "冒険者アカデミーに";
		mes "行ったことはあるか？";
		next;
		mes "[鳳凰]";
		mes "己を磨くために、";
		mes "基本となることを";
		mes "学ぶのであれば、";
		mes "行ってみるといい。";
		next;
		mes "[鳳凰]";
		mes "そこに、冒険者アカデミーの";
		mes "サポートを行っている者が";
		mes "見えるだろう。";
		mes "あの者の力で送って";
		mes "もらうといい。";
		next;
		mes "[鳳凰]";
		mes "常に精進し、更なる上を";
		mes "絶えず追い求める心を";
		mes "忘れぬようにな。";
		close;
	}
	if(Upper == Upper_BABY) {
		mes "[鳳凰]";
		mes "俺は、正しき修練を通じて、";
		mes "健全な精神を養うと同時に、";
		mes "己の修練で悟った道を";
		mes "世に広めることを決心した。";
		mes "恐らく、それこそが、";
		mes "俺にできる最善の事である。";
		close;
	}
	if(Job == Job_Novice && Upper == UPPER_NORMAL && CHANGE_TK == 3) {
		mes "[鳳凰]";
		mes "心の準備はできたか？";
		mes "それでは最後の質問だ。";
		mes "そんなに大したことではないが、";
		mes "飾らず素直な気持ちを聞きたい。";
		next;
		mes "[鳳凰]";
		mes "^FF0000今まで話してきた道を";
		mes "受け入れることができるか？";
		mes "そして、その道を進む努力はできるか？";
		mes "孤独な道だ。それだけの覚悟は";
		mes "できているか？^000000";
		mes "さあ、答えろ。";
		next;
		if(select("はい！","まだ……")==2) {
			mes "[鳳凰]";
			mes "……まだ覚悟が足りないようだな。";
			mes "真の修練者になるにはまだ早い。";
			mes "きちんと、覚悟を決めてからこい。";
			mes "素直なのはいいことだが、";
			mes "それだけではこの険しい道を";
			mes "進むことはできないのでな。";
			close;
		}
		mes "[鳳凰]";
		mes "よし！　それほどの覚悟があるなら、";
		mes "もう何も言うまい。";
		mes "いや、これ以上お前が";
		mes "何かする必要もない。";
		mes "その精神を持っている時点で、";
		mes "お前はもう立派な修練者だ。";
		next;
		mes "[鳳凰]";
		mes "私が歩む道の名は……";
		mes "まあ、名は重要なことではないが、";
		mes "とにかく、この道の名は、";
		mes "^FF0000テコンドー^000000と言う。";
		mes "テコンドーのテコンは足と拳を、";
		mes "ドーは道を意味する。";
		next;
		mes "[鳳凰]";
		mes "四肢を利用し、技へ組み込む。";
		mes "それがすなわち修練だ。";
		mes "四肢を100%活用し、";
		mes "正しい精神を持っていれば、";
		mes "そこから派生する技術は";
		mes "自然に使うことができるだろう。";
		next;
		mes "[鳳凰]";
		mes "今後、その精神を大事にし、";
		mes "また他の修練者にも伝えるとよい。";
		mes "たとえ伝えることができなくとも、";
		mes "修練を続けることに意義はある。";
		next;
		nude;
		getitem 11043,1;
		getitem 2101,1;
		jobchange Job_Taekwon;
		set CHANGE_TK,0;
		chgquest 6002,50220;
		mes "[鳳凰]";
		mes "お前……ふむ、そうだな……";
		mes "きちんとした呼び名をつけてあげよう。";
		mes "「テコンキッド」だ。";
		mes "良い名だろ？";
		mes "自信を持っていいぞ。";
		next;
		mes "[鳳凰]";
		mes "これは、修練するのに";
		mes "一番良い服装と鍛錬時に";
		mes "自分の身を守ってくれる盾だ。";
		mes "是非、使ってくれ。";
		next;
		mes "[鳳凰]";
		mes "さあ、それじゃあ行け！";
		mes "お前のその健全な精神と";
		mes "これから鍛えられる肉体を武器にして、";
		mes "世の中を浄化しろ！";
		mes "修練だからといって、必ずしも";
		mes "山にこもって一人でいる必要はない。";
		next;
		mes "[鳳凰]";
		mes "困難にぶつかったら、";
		mes "いつでも私のところへ来い。";
		mes "簡単な助言位ならいつでもしてやる。";
		mes "しかし基本的に、大体のことは";
		mes "お前の力だけで解決できるだろうから、";
		mes "それは忘れずにな。";
		next;
		mes "[鳳凰]";
		mes "もし、進むべき道が";
		mes "わからなくなった時は";
		mes "テコンキッドの書を見るといい。";
		mes "参考になるはずだ。";
		close;
	}
	if(Job == Job_Novice && Upper == UPPER_NORMAL && CHANGE_TK == 2) {
		mes "[鳳凰]";
		mes "よし、準備ができたようだな。";
		mes "では、講義に入ろう。";
		mes "ああ、精神を試すとは言ったが、";
		mes "そんなに大げさなことではない。";
		mes "単に当たり前なことを問い、";
		mes "その当たり前なことを覚えるだけだ。";
		next;
		mes "[鳳凰]";
		mes "それを終えれば、お前は立派な";
		mes "修練者としての資格があると認めよう。";
		mes "簡単な問答だから";
		mes "別に緊張することはないぞ。";
		next;
		mes "[鳳凰]";
		mes "一つ目は、意志に関することだ。";
		mes "修練の道……この道はとても険しい。";
		mes "他の楽しみと休息を全て";
		mes "捨てなければならない";
		mes "辛く寂しく長い道のりだ。";
		next;
		mes "[鳳凰]";
		mes "また、この道を進む途中には";
		mes "多くの困難が待ち受けているだろう。";
		next;
		mes "[鳳凰]";
		mes "そこで、その困難に直面した時、";
		mes "お前はどうする？";
		mes "いくつかの例を挙げるから、";
		mes "その中から正しいと思うものを";
		mes "選んでくれ。";
		next;
		switch(select("困難に立ち向かう","他の道を模索する","しばしの間休息をとり、再度態勢を整える")) {
		case 1:
			mes "[鳳凰]";
			mes "よし、正解だ。";
			mes "困難に直面した時は、";
			mes "たとえすぐには解決できそうに";
			mes "ないことであっても";
			mes "直接ぶつかる方がよい。";
			next;
			mes "[鳳凰]";
			mes "また、いかなる事情があったとしても";
			mes "自分の信念を貫くためには、";
			mes "死さえ恐れてはいけない。";
			next;
			mes "[鳳凰]";
			mes "そして、自身を信じ、";
			mes "強靭な信念と初志貫徹の精神。";
			mes "それらを抱いて突き進めば、";
			mes "己の前に立ちはだかれるものなど";
			mes "無きに等しいであろう。";
			next;
			mes "[鳳凰]";
			mes "万が一あったとしても、";
			mes "そんなのは大した障害とは";
			mes "ならないはずだ。";
			next;
			mes "[鳳凰]";
			mes "もし、すぐにはその困難を";
			mes "突破できなくとも、それに立ち向かう";
			mes "過程において己の肉体は成長する。";
			mes "よって、お前のその答えは完璧だ。";
			next;
			mes "[鳳凰]";
			mes "意志に関しては、これ以上";
			mes "俺が言うことはない。";
			mes "それでは次の項目にいこう。";
			break;
		case 2:
			mes "[鳳凰]";
			mes "馬鹿者めっ!!";
			mes "他の道を模索するだとぉ〜?!";
			mes "辛いからといって、";
			mes "修練の道へ進むという自分の決意を";
			mes "そんなに簡単に曲げるつもりなのか！";
			next;
			mes "[鳳凰]";
			mes "もちろん、他の道を捜すこと自体は";
			mes "一つの方法だ。人生において、";
			mes "自分に合わないような困難な道に";
			mes "敢えて進むことはない。";
			next;
			mes "[鳳凰]";
			mes "そう考えれば、";
			mes "これこそがより賢明な";
			mes "方法かもしれない。";
			next;
			mes "[鳳凰]";
			mes "だが、まだこの道を一歩たりとも";
			mes "歩んでいない状態において、";
			mes "困難があると仮定しただけで";
			mes "自分が決心したことを簡単に";
			mes "翻すとは言語道断だ！";
			mes "有り得ん！";
			next;
			mes "[鳳凰]";
			mes "考えを改めて来い！";
			mes "今のお前の精神状態では、";
			mes "修練どころか、他の何事も成すことが";
			mes "できないだろう。";
			mes "そんな情けない状態であることを";
			mes "自覚し、まずは心構えから見直せ！";
			close;
		case 3:
			mes "[鳳凰]";
			mes "休息か……それもいいな。";
			mes "どうしても駄目な時はしばらく休んで、";
			mes "態勢を整えるというのも一つの方法だ。";
			mes "一時、道から外れてはしまうが、";
			mes "だからといって、常に走り続ける";
			mes "必要はない。";
			next;
			mes "[鳳凰]";
			mes "歩むことも、少しの間座すことも、";
			mes "一つの道を守る立派な方法と";
			mes "言えるだろう。";
			next;
			mes "[鳳凰]";
			mes "しかし、それも自分の能力の全てを";
			mes "費やして最善を尽くした時にこそ";
			mes "言えることだ。";
			mes "困難にぶつかっても、休む前に";
			mes "まず最善を尽くし、";
			mes "限界に挑むべきである。";
			next;
			mes "[鳳凰]";
			mes "極限状態になっても尚、";
			mes "解決し得ぬことであれば、";
			mes "しばしの間疲れた身を立て直すために";
			mes "休むという選択もまた当然だ。";
			mes "もちろん困難を打ち破った後に、";
			mes "ゆっくりと休むのも良い。";
			next;
			mes "[鳳凰]";
			mes "よって、しばしの間休息をとり、";
			mes "再度態勢を整えるというのは";
			mes "完璧な正解ではない。";
			mes "もう一度、よく考えてから来い。";
			close;
		}
		next;
		mes "[鳳凰]";
		mes "今度は自分以外のことに関する質問だ。";
		mes "よく聞いて答えるように。";
		next;
		mes "[鳳凰]";
		mes "修練の道を歩いていると、";
		mes "好む好まずに限らず、";
		mes "多少なりとも";
		mes "人とぶつかることがあるだろう。";
		next;
		mes "[鳳凰]";
		mes "それは、この修練の道が、";
		mes "人間の本能や本来の欲求に";
		mes "相反するものであるから、";
		mes "仕方ないことなのである。";
		next;
		mes "[鳳凰]";
		mes "そういう特殊な道だ。";
		mes "一般から逸脱しているこの道を";
		mes "他の人は理解できず、";
		mes "また、こちらも一般的なことを";
		mes "理解できないかもしれない。";
		next;
		mes "[鳳凰]";
		mes "そんな意識の違いから、";
		mes "人と衝突することは逃れられる";
		mes "ものではないということだ。";
		mes "理由はなんであれ、";
		mes "このように衝突した時、";
		mes "お前はどうする？";
		next;
		switch(select("どうあっても信念を貫く","水に流して、我が道を行く","全てを認め、道を進み続ける")) {
		case 1:
			mes "[鳳凰]";
			mes "頑なに初志貫徹を守る心は良い。";
			mes "しかし、いくら孤独な道へ進むと";
			mes "いっても、人は所詮、多くの人と";
			mes "共に生きるもの。";
			next;
			mes "[鳳凰]";
			mes "それにも関わらず、自分の信念のみを";
			mes "貫くことに固執し、";
			mes "他の者へもそれを強要するというのは";
			mes "危険な考えだ。";
			next;
			mes "[鳳凰]";
			mes "しかも、こんなに険しい道、難解な思想を";
			mes "他人に理解させるのは好ましい";
			mes "ことではない。";
			mes "こんな孤独で辛い修練の道を行く者は";
			mes "少数で十分なのだ。";
			next;
			mes "[鳳凰]";
			mes "寂しく孤独な道を進まねばならない。";
			mes "だからこそ、修練者を増やしたいと";
			mes "思う心は理解できる。";
			mes "しかし、それを他人に強要することは";
			mes "できない。";
			next;
			mes "[鳳凰]";
			mes "解るか？　お前のその信念を";
			mes "守り抜こうとする心意気はよいが、";
			mes "正解ではない。";
			next;
			mes "[鳳凰]";
			mes "よって、もう一度考えてみろ。";
			mes "信念を貫くのは望ましいことだが、";
			mes "人間は決して一人で";
			mes "生きて行くことはできない";
			mes "存在であるということも";
			mes "肝に銘じておくように。";
			close;
		case 2:
			mes "[鳳凰]";
			mes "さっきも話したが、困難に直面した時、";
			mes "一度立ち向かうことが大事だ。";
			mes "だが、二つの道があったこと自体を";
			mes "なかったことにして、";
			mes "自分の道を進むというのは、";
			mes "逃げに近いことである。";
			next;
			mes "[鳳凰]";
			mes "思いっきり衝突して、";
			mes "あまりにも強圧的な姿を";
			mes "見せつけるのは問題だ。";
			mes "どの程度主張を通し、妥協するか……";
			mes "それは、きちんと立ち向かってから";
			mes "決めなければならない。";
			next;
			mes "[鳳凰]";
			mes "そんなわけで、自分の道を進むという";
			mes "ことはとても望ましい事だが、";
			mes "他人が何を言ってきても話を聞かずに、";
			mes "自分の意見すら主張せずに";
			mes "突き進むというのはよろしくない。";
			next;
			mes "[鳳凰]";
			mes "だから、もう一度考えてみろ。";
			mes "自分の道を進むというのは";
			mes "決して間違ってはいないが、";
			mes "他人と衝突した時は";
			mes "他の視点からの意見も考える方がよい。";
			close;
		case 3:
			mes "[鳳凰]";
			mes "自分だけでなく、";
			mes "他人のいかなる意見や信念を";
			mes "認めるというのは、";
			mes "かなり大変なことだ。";
			mes "実行するのは、困難だろう。";
			next;
			mes "[鳳凰]";
			mes "しかし、互いを、また他方を";
			mes "理解しようと努力する、";
			mes "その過程こそ修練なのだ。";
			mes "決して、この過程を避けてはいけない。";
			next;
			mes "[鳳凰]";
			mes "相手を理解することができなくても、";
			mes "認めることはできる。";
			mes "そのように心がければ、";
			mes "相手も心を開き、認められるための";
			mes "努力をしようとするはずだ。";
			next;
			mes "[鳳凰]";
			mes "お前は純粋な心で相手の努力を";
			mes "受け入れれば良いのだ。";
			next;
			mes "[鳳凰]";
			mes "そして、一つの信念を認め、";
			mes "それを受け入れられるようになったら、";
			mes "その時、お前は一歩先へ";
			mes "進むことができるだろう。";
			mes "解ったか？";
			mes "そうだ、お前の選択は間違ってない。";
			next;
			mes "[鳳凰]";
			mes "よし、精神面の適正検査は";
			mes "これで終わりだ。";
			mes "最後の質問の前に、少し休みな。";
			mes "お前も一度に多くの話を聞いて";
			mes "疲れただろう。";
			mes "少し休憩したら、また声をかけろ。";
			set CHANGE_TK,3;
			chgquest 6001,6002;
			close;
		}
	}
	if(Job == Job_Novice && Upper == UPPER_NORMAL && CHANGE_TK == 1) {
		if(BaseLevel > CHANGE_TK_LV) {
			mes "[鳳凰]";
			mes "うん？";
			mes "この感じは……そうか……";
			mes "言った通り修練してきたんだな。";
			mes "では約束通りお前の精神を試そう。";
			mes "少し深呼吸をして、準備が整ったら";
			mes "声をかけてくれ。";
			set CHANGE_TK_LV,0;
			set CHANGE_TK,2;
			chgquest 6000,6001;
			close;
		}
		mes "[鳳凰]";
		mes "お前が今すべきことは、";
		mes "^FF0000BaseLvをもう少し上げることだ。^000000";
		mes "俺の忠告は忘れていないよな？";
		mes "さあ、修練してこい！";
		mes "若者よ。";
//		next;
//		mes "[鳳凰]";
//		mes "お前ひとりの力で";
//		mes "修練することもできるが、";
//		mes "己を鍛えるためには";
//		mes "最適な環境も必要だろう。";
//		mes "^0000FF冒険者アカデミーという所は";
//		mes "お前の成長の手助けになるはずだ。^000000";
//		next;
//		mes "[鳳凰]";
//		mes "すぐそこに、アカデミーのサポートを";
//		mes "している人がいるのが見えるか？";
//		mes "あの者に話しかけ、";
//		mes "^0000FF冒険者アカデミーに行き、";
//		mes "己を鍛えてくるがいい。^000000";
		close;
	}
	mes "[鳳凰]";
	mes "俺の名は、鳳凰。";
	mes "悪からこの世を浄化するため、";
	mes "自ら精進し、鍛える修行者だ。";
	mes "本名は、修練開始時に捨て、";
	mes "「鳳凰」と名乗っている。";
	mes "俺のことは、鳳凰と呼んでくれ。";
	next;
	mes "[鳳凰]";
	mes "世の中をどうやって浄化させるかだと？";
	mes "良い質問だ。このような話をする";
	mes "機会は滅多にないから、";
	mes "きちんと耳を傾けるように。";
	next;
	mes "[鳳凰]";
	mes "世の中が悪で染まる理由は、";
	mes "健全な精神を養えなかった人間が";
	mes "多くなったからだと、俺は思う。";
	mes "しかも、世知辛い世の中では";
	mes "人間関係だけでも大変なのに、";
	mes "モンスターも多数生息している。";
	next;
	mes "[鳳凰]";
	mes "こんなに暮らしにくい世に生きる";
	mes "弱い人間たちにとっては、";
	mes "健全な精神を持てないのは";
	mes "仕方ないことかもしれない。";
	next;
	mes "[鳳凰]";
	mes "しかし、そのような状況が";
	mes "わかっているからといって、";
	mes "この世が悪で染まっていくのを";
	mes "ただ指をくわえて";
	mes "見ているわけにもいかない。";
	mes "そこで世のために俺は立ち上がった！";
	next;
	mes "[鳳凰]";
	mes "だが……俺も単なる";
	mes "人間の一人にすぎない。";
	mes "そんな俺が、どうすれば";
	mes "世の中を変えることができるのか。";
	next;
	mes "[鳳凰]";
	mes "それが俺が名を捨ててまで、";
	mes "修行者になった理由だ。";
	mes "世の中を変えるには、";
	mes "己が強くならなければならない。";
	next;
	mes "[鳳凰]";
	mes "そう……健全な精神は、";
	mes "健康な肉体に宿る。";
	mes "もちろん、健康な肉体を持ちながらも";
	mes "悪事を働く人間も存在する。";
	mes "それは、真の意味で健康な肉体を";
	mes "持つことができなかったからであろう。";
	next;
	mes "[鳳凰]";
	mes "もしくは、健康な肉体のみを追求し、";
	mes "精神の修練を怠ったせいかもしれない。";
	mes "いずれにしても、";
	mes "望ましくない状況ということは確かだ。";
	next;
	mes "[鳳凰]";
	mes "俺は、正しき修練を通じて、";
	mes "健全な精神を養うと同時に、";
	mes "己の修練で悟った健全な精神の道を";
	mes "世に広めることを決心した。";
	mes "恐らく、それこそが、";
	mes "俺にできる最善の事である。";
	if(Job != Job_Novice || Upper != UPPER_NORMAL)
		close;
	next;
	mes "[鳳凰]";
	mes "そこでお前、まだ進むべき道を";
	mes "決めていなければ、";
	mes "過酷な修練に臨み、";
	mes "世の中を浄化する戦いに";
	mes "その身を投じないか？";
	next;
	mes "[鳳凰]";
	mes "それは確かに意味のある";
	mes "戦いになるはずだ。";
	next;
	mes "[鳳凰]";
	mes "では、選ぶがよい。";
	mes "よく考え、";
	mes "賢明な選択をした方がいいぞ。";
	next;
	if(select("賛同する","賛同しない")==2) {
		mes "[鳳凰]";
		mes "そうか……人間が生きていく上で";
		mes "選ぶ道は無限にあるが、";
		mes "当然、全ての道を選ぶことはできない。";
		mes "だから自分に合わない道を";
		mes "捨てることもまた、賢明である。";
		mes "己の選択に自信を持つとよい。";
		next;
		mes "[鳳凰]";
		mes "どの道に進むかは、";
		mes "己の心を信じればよい。";
		mes "己の信念を貫けば、";
		mes "それがいつか、世の浄化に";
		mes "つながるかもしれないな。";
		close;
	}
	if(getskilllv(1) < 9) {
		mes "[鳳凰]";
		mes "……残念だが、";
		mes "お前が俺と共に同じ道を歩むには、";
		mes "^0000FF「基本スキル」が足りない。";
		mes "JobLvを10まで上げ、";
		mes "^0000FF「基本スキル」が9　^000000になったら";
		mes "来るんだな！";
		next;
		mes "[鳳凰]";
		mes "^0000FF「基本スキル」^000000のレベルは";
		mes "^0000FF「スキルリスト」^000000ウィンドウで";
		mes "上げることができる。";
		mes "^0000FF「スキルリスト」^000000ウィンドウは";
		mes "^0000FF「基本情報」^000000ウィンドウ内の";
		mes "^0000FF「Skill」^000000ボタンで表示される。";
		next;
		mes "[鳳凰]";
		mes "スキルのレベルを上げるには、";
		mes "スキルポイントを割り振った後、";
		mes "^FF0000「確定」^000000ボタンが必要だぞ。";
		mes "注意しろよ。";
		close2;
		cutin "start_020_jp.bmp",4;
		end;
	}
	mes "[鳳凰]";
	mes "よし、ならばすぐに始めよう。";
	mes "健全な精神も重要だが、";
	mes "まずはどの程度肉体が鍛えられて";
	mes "いるかを見よう。";
	next;
	if(BaseLevel >= 20) {
		mes "[鳳凰]";
		mes "……その必要はなさそうだな。";
		mes "特定の職業に就いていない";
		mes "ノービスの段階で、それだけ";
		mes "強靭な肉体と強さを";
		mes "持ち合わせていれば十分だ。";
		next;
		mes "[鳳凰]";
		mes "よし、肉体的な力と意志の強さに";
		mes "関してはもう試す必要はないな。";
		mes "次にお前の精神を試そう。";
		mes "少し深呼吸をして、心の準備が";
		mes "整ったら声をかけてくれ。";
		set CHANGE_TK,2;
		setquest 6001;
		close;
	}
	mes "[鳳凰]";
	mes "今のお前は、どう見ても";
	mes "修練に耐えられる強さにまでは";
	mes "達していない。";
	mes "確かに修練を通じて強くはなるが、";
	mes "今の状態では成果は出せないだろう。";
	next;
	mes "[鳳凰]";
	mes "そんなわけで、^FF0000BaseLvを";
	mes "もう少し上げてこい。^000000";
	next;
	mes "[鳳凰]";
	mes "ノービスの状態で、";
	mes "モンスターと戦って勝ち抜き、";
	mes "それを繰り返して強くなる……";
	mes "かなり辛く険しい道だが、";
	mes "これは、肉体の可能性とお前の意志を";
	mes "試すためのものだ。この位は簡単だろ。";
	next;
	set CHANGE_TK_LV,BaseLevel;
	set CHANGE_TK,1;
	setquest 6000;
	mes "[鳳凰]";
	mes "さあ、行け！";
	mes "だが、案ずることはない。";
	mes "何かを切に望めば、この世は";
	mes "お前の願いに応えるだろう。";
	next;
	mes "[鳳凰]";
	mes "たとえ、この世がお前の願いに";
	mes "応えなかったとしても、";
	mes "お前の意志をもってすれば、";
	mes "十分にやり遂げられると信じているぞ。";
//	next;
//	mes "[鳳凰]";
//	mes "とはいえ、お前ひとりの力を";
//	mes "過信しているわけではない。";
//	mes "己を鍛えるためには";
//	mes "最適な環境も必要だろう。";
//	mes "^0000FF冒険者アカデミーという所は";
//	mes "お前の成長の手助けになるだろう。^000000";
//	next;
//	mes "[鳳凰]";
//	mes "そこにアカデミーのサポートを";
//	mes "している人がいる。";
//	mes "あの者に話しかけ、";
//	mes "^0000FF冒険者アカデミーに行き、";
//	mes "己を鍛えてくるがいい。^000000";
	close;
OnInit:
	waitingroom "転職",0;
	end;
}
