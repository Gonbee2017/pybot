//====================================================================
//Ragnarok Online StarGladiator Jobchange Script
//　■ CHANGE_SG -> 0〜12
//====================================================================

//==========================================
// 試験申請
//------------------------------------------

payon,215,102,3	script	ムヒョン	828,3,3,{
	if(Job == Job_Star) {
		mes "[ムヒョン]";
		mes "おや……君は……";
		mes "太陽と月と星の戦士じゃないか!?";
		mes "はは、久しぶりだね！";
		mes "僕のこと憶えてる？";
		mes "うまくやってるようだね。";
		mes "アハハッ！";
		close;
	}
	if(Job == Job_Novice) {
		mes "[ムヒョン]";
		mes "何か用かい？";
		mes "君もテコンキッドになりたいのかな？";
		mes "なら、正義しか知らない「鳳凰」";
		mes "というやつに会いに行ってごらん。";
		mes "近くにいるはずだからすぐ見つかるよ。";
		next;
		mes "[ムヒョン]";
		mes "ずーっと先の事だけど……";
		mes "テコンドーに飽きた頃に、";
		mes "また僕の所に来てごらん。";
		mes "フフ。";
		close;
	}
	if(Job != Job_Taekwon) {
		mes "[ムヒョン]";
		mes "用も無しにあまりつっつかないでよ。";
		if(Sex) {
			mes "お兄さんは男に";
			mes "わき腹を突付かれたいの？";
			mes "まさか変な趣味が!?";
		}
		else {
			mes "いや、お姉さんじゃしょうがないか。";
			mes "そんなに俺に興味があるなら";
			mes "両腕いっぱい広げて抱きついて";
			mes "あげようか？　フフ。";
		}
		next;
		mes "[ムヒョン]";
		mes "…………………………";
		mes "はい、はい。";
		mes "冗談はここまでにするから。";
		mes "そんなに怒らないでよ。";
		next;
		mes "[ムヒョン]";
		mes "俺はこう見えても";
		mes "昔は太陽と月と星の戦士だったんだぞ。";
		next;
		mes "[ムヒョン]";
		mes "信じることができないって？";
		mes "なら俺に子供達を任せて見なよ。";
		mes "すごい拳聖にして";
		mes "送りかえしてやるんだから！";
		close;
	}
	switch(CHANGE_SG) {
	case 0:
		mes "[ムヒョン]";
		mes "やぁ、テコン" +(Sex)? "少年！": "少女！";
		mes "俺とちょっとお話しない？";
		mes "なになに、すぐ終わるって。";
		next;
		if(select("いいですよ","嫌です！")==2) {
			mes "[ムヒョン]";
			mes "きっぱりと言うねぇ。";
			mes "ちょっと言葉使いが悪いよ。";
			mes "次に断る時は";
			mes "もう少し相手を気遣ってね。";
			close;
		}
		mes "[ムヒョン]";
		mes "名前は？";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes strcharinfo(0)+"。";
		next;
		mes "[ムヒョン]";
		mes "無愛想だなぁ。";
		mes strcharinfo(0)+"です。";
		mes "これぐらい言わなくちゃ。";
		next;
		mes "[ムヒョン]";
		mes "そうそう、君って将来何になりたい？";
		mes "もしよかったら";
		mes "^4A4AFF太陽と月と星の戦士^000000";
		mes "にならないか？";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "それは何ですか？";
		mes "初耳ですが……";
		mes "私が知っているのは";
		mes "「ソウルリンカー」と「拳聖」、";
		mes "この二つだけです。";
		next;
		mes "[ムヒョン]";
		mes "へぇ……よく知ってんじゃん。";
		mes "君が今言った「拳聖」の事が";
		mes "太陽と月と星の戦士のことさ。";
		mes "とっても魅力的な職業だよ。";
		mes "君は拳聖になりたくないの？";
		next;
		if(select("私の目標です！","べつに……")==2) {
			mes "[ムヒョン]";
			mes "そっかぁ。";
			mes "君はソウルリンカーより拳聖のほうが";
			mes "似合ってると思うんだけどなぁ……";
			mes "ま、まさか！";
			mes "永遠にテコンキッドでいたいの!?";
			next;
			mes "[ムヒョン]";
			mes "ウウウウ……";
			mes "まぁ……";
			mes "心変わりでもしたらまたおいでよ。";
			mes "いつでも拳聖にしてあげるからさ。";
			close;
		}
		mes "[ムヒョン]";
		mes "目標か……";
		mes "やっぱりそうか！";
		mes "俺の目は確かだった！";
		mes "君の将来は拳聖だ。";
		next;
		if(JobLevel < 40) {
			mes "[ムヒョン]";
			mes "でも……";
			mes "まだちょっとレベル不足かな……";
			mes "テコンキッドでの修練を";
			mes "もう少し詰まないと。";
				mes "せめてジョブレベル40はないとね。";
			next;
			mes "[ムヒョン]";
			mes "もう少し力を付けてからまたおいで。";
			mes "よし、俺と約束しよう。";
			mes "必ず拳聖になるってね！";
			close;
		}
		mes "[ムヒョン]";
		mes "良いね！　修練も詰んでいるし";
		mes "身も心も頑丈そうだ。";
		mes "だけど、そんな君にも";
		mes "一つ足りない所がある……";
		mes "そう、先生だ！";
		next;
		mes "[ムヒョン]";
		mes "君を太陽と月と星の戦士へと";
		mes "導いてくれる先生だ。";
		mes "よかったらその人を紹介してあげるよ。";
		mes "だからもう一度聞くよ。";
		next;
		mes "[ムヒョン]";
		mes "^4A4AFF拳聖に転職^000000するかい？";
		next;
		if(select("転職します","考える時間をください")==2) {
			mes "[ムヒョン]";
			mes "そっか。";
			mes "まぁ、拳聖になりたくなったら";
			mes "いつでもおいでよ。";
			close;
		}
		mes "[ムヒョン]";
		mes "よし！　良い答えだ。";
		mes "それじゃあ";
		mes "君に先生を紹介してあげるよ。";
		mes "見てわかるように、俺たちには";
		mes "後輩育成のためのギルドはないんだ。";
		next;
		mes "[ムヒョン]";
		mes "しかし、そのおかげで";
		mes "何をしてもいい自由が与えられる。";
		mes "おかげで連絡が取り辛くなるけどね……";
		next;
		mes "[ムヒョン]";
		mes "……とにかく、そういうことだから。";
		mes "俺は先生の居場所を知っているから、";
		mes "教えてあげるよ。";
		next;
		mes "[ムヒョン]";
		mes "^4A4AFFムガン^000000という先生だ。";
		mes "この人は拳聖の中で一番";
		mes "後輩のためにがんばっている人だよ。";
		mes "その人に紹介状を書いてあげるよ。";
		next;
		mes "[ムヒョン]";
		mes "「ムガン」先生は今コモドにいるよ。";
		mes "コモドは一番空に近いんだ。";
		mes "必ずその人を訪ねてね。";
		set CHANGE_SG,1;
		close;
	case 1:
		mes "[ムヒョン]";
		mes "コモドにいる「ムガン」先生に";
		mes "会いに行って。";
		mes "もう紹介状は送ってあるよ。";
		close;
	default:
		mes "[ムヒョン]";
		mes "太陽と月と星の戦士になるための試験は";
		mes "はかどっているかな？";
		mes "君は拳聖になるんだろ。";
		if(CHANGE_SG != 6)
			close;
		next;
		mes "[ムヒョン]";
		mes "おや、どうも顔色がよくないね。";
		mes "何か困っているの？";
		mes "なんなら俺が手伝ってあげようか？";
		next;
		if(select("いえ、一人でやってみるつもりです","実は、ピリュ先生の事で")==1) {
			mes "[ムヒョン]";
			mes "そうだね。";
			mes "一人で悩んでみるのもいいかも。";
			mes "拳聖への道は今までとは違うんだ。";
			mes "自分で判断しなければならない時が";
			mes "必ず来るからね。";
			next;
			mes "[ムヒョン]";
			mes "だから、とても慎重な人こそが";
			mes "拳聖だと言えるんだ。";
			mes "人生は「やるぞ！　いやだ！」";
			mes "って簡単に行ったり来たり";
			mes "することができないもんだろ。";
			close;
		}
		mes "[ムヒョン]";
		mes "ピリュ様が何て言ったかは";
		mes "聞かなくてもわかるよ。";
		mes "特に何かを持って行く必要は";
		mes "ないんだ。";
		next;
		mes "[ムヒョン]";
		mes "難しく考えていたね。";
		mes "必ずしも何かを持って行って";
		mes "証明する必要なんてないんだよ。";
		next;
		mes "[ムヒョン]";
		mes "分からないかな？";
		mes "自分の信念は自分にしか";
		mes "証明することができないという";
		mes "とても簡単な論理さ。";
		next;
		mes "[ムヒョン]";
		mes "「やりたい！」";
		mes "「あきらめるもんか！」";
		mes "「後悔はしない！」";
		mes "誰だって言うことでしょ？";
		next;
		mes "[ムヒョン]";
		mes "皆が自分の信念のために";
		mes "自身を奮い立たせている。";
		mes "人々はそんな日常の中で住んでる。";
		next;
		mes "[ムヒョン]";
		mes "がんばってお金を稼いで、";
		mes "食いつなぎながらも生きて行く人々。";
		mes "皆自分が……";
		mes "今、この場で生きていることを、";
		mes "存在していることを証明するために";
		mes "努力しているんだ。";
		next;
		mes "[ムヒョン]";
		mes "これで答えが出ない？";
		mes "君の胸の中にある答えは何だい？";
		next;
		if(select("あきらめたくない！","何の事か分からない")==2) {
			mes "[ムヒョン]";
			mes "…………………………そっか。";
			mes "ここまで色々と話したけど、";
			mes "やる気はあるの？";
			next;
			mes "[ムヒョン]";
			mes "しばらく頭を冷やしておいで。";
			mes "俺が何のために……";
			mes "誰のために熱弁をしたのか……";
			close;
		}
		mes "[" +strcharinfo(0)+ "]";
		mes "私はあきらめたくない！";
		mes "今ここには、私自身の意志で";
		mes "私が持つ二つの足で立っている";
		mes "この私がいるだけだ！";
		next;
		mes "[ムヒョン]";
		mes "そう！　良い姿勢だ！";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "私は自分の意志でこの道を歩いている！";
		mes "それを証明するのは自分だけ。";
		mes "私は拳聖になる!!!!";
		next;
		mes "[ムヒョン]";
		mes "そう！　あきらめるな！";
		mes "対立して戦え！";
		mes "相手の二つの目を見つめながら";
		mes "首を傾げる者が卑怯者だ！";
		next;
		mes "[ムヒョン]";
		mes "君は、その身と心で！";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "私の体と心で！";
		mes "自分を証明する！";
		next;
		mes "[ムヒョン]";
		mes "よく言った！";
		mes "気合い十分って感じだよ。";
		mes "このままムガン先生に会えば";
		mes "月の部屋に送ってくれるよ。";
		mes "今度会う時は拳聖でね！";
		set CHANGE_SG,7;
		close;
	case 7:
		mes "[ムヒョン]";
		mes "ムガン先生に言えば";
		mes "月の部屋に送ってくれるよ。";
		mes "今度会う時は拳聖でね！";
		close;
	}
OnTouch:
	if(Job == Job_Star) {
		mes "[ムヒョン]";
		mes "おや……君は……";
		mes "太陽と月と星の戦士じゃないか!?";
		mes "はは、久しぶりだね！";
		mes "僕のこと憶えてる？";
		mes "うまくやってるようだね。";
		mes "アハハッ！";
		close;
	}
	if(Job != Job_Taekwon) {
		mes "[ムヒョン]";
		mes "ちょっと！　そこどいてよ！";
		mes "太陽の光が当たらないだろ！";
		close;
	}
	if(CHANGE_SG == 0) {
		mes "[ムヒョン]";
		mes "ねぇねぇ、そこの君。";
		mes "ちょっと俺の話を聞いて見ない？";
		mes "すぐ済むからさ。";
		close;
	}
}

//==========================================
// 転職
//------------------------------------------

comodo,172,230,3	script	放浪武道家	730,{
	if(Job == Job_Star) {
		mes "[ムヒョン]";
		mes "久しぶりだな。";
		mes "最近はどこに？";
		mes "ハハッ。";
		mes "もちろん";
		mes "太陽と月と星の祝福が下りる所だな。";
		next;
		mes "[ムヒョン]";
		mes "私の忠告を忘れないように。";
		mes "私たちは一回の選択で人生が決まる。";
		mes "君には後悔しない選択をしてほしい。";
		next;
		mes "[ムヒョン]";
		mes "もし、";
		mes "太陽と月と星明かりが懐かしいなら、";
		mes "いつでも言いなさい。";
		mes "すぐに送ってあげよう。";
		mes "今、見に行くか？";
		next;
		switch(select("いえ、いいです","太陽の部屋に！","月の部屋に！","星の部屋に！")) {
		case 1:
			mes "[ムヒョン]";
			mes "そうか。";
			mes "私はいつでもここにいるから";
			mes "いつでもきなさい。";
			close;
		case 2:
			mes "[ムヒョン]";
			mes "太陽がくれる豊かさと";
			mes "熱い情熱を授かってくるといい。";
			close2;
			warp "job_star",34,12;
			end;
		case 3:
			mes "[ムヒョン]";
			mes "何かじっくりと考えることがあるのか？";
			mes "月明りの物静けさから";
			mes "何か学んでくるといい。";
			close2;
			warp "job_star",100,13;
			end;
		case 4:
			mes "[ムヒョン]";
			mes "おぼろげな星明かりは";
			mes "夢を見れるようにしてくれる。";
			mes "それとも失恋でもしたのか？";
			mes "ハハッ、冗談だ。";
			close2;
			warp "job_star",166,29;
			end;
		}
	}
	if(Job != Job_Taekwon) {
		mes "[放浪武道家]";
		mes "君も山行を楽しんでるのか？";
		mes "高い所から下を見下ろせば";
		mes "胸の中が開けて涼しくなるな。";
		next;
		mes "[放浪武道家]";
		mes "月明りと星明かりが一杯な";
		mes "夜の余韻の中ではその楽しみが";
		mes "倍加される……";
		next;
		mes "[放浪武道家]";
		mes "ハッハ……";
		mes "私にはそれが見えないという";
		mes "ことが問題だな。";
		next;
		mes "[放浪武道家]";
		mes "ささやかだが";
		mes "君の将来に";
		mes "太陽と月と星の祝福が";
		mes "与えられる事を祈ろう。";
		close;
	}
	switch(CHANGE_SG) {
	case 0:
		mes "[ムガン]";
		mes "テコンドーを修練しているのか。";
		mes "やはり君のような人には";
		mes "ついつい目がいってしまうな。";
		mes "失礼。";
		mes "私の名は「ムガン」と言う。";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes strcharinfo(0)+ "です。";
		next;
		mes "[ムガン]";
		mes "…………君…………";
		mes "^4A4AFF拳聖になる気はないか？^000000";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "……………………";
		mes "…………あ……いや……あの…………";
		next;
		mes "[ムガン]";
		mes "あぁ、これは失礼をした。";
		mes "聞かなかったことにしてくれ。";
		mes "ハッハハハ。";
		next;
		mes "[ムガン]";
		mes "私たちは太陽と……月と……星と……";
		mes "……ムヒョンよ……ムヒョンよ……";
		mes "……ブツブツ…………";
		close;
	case 1:
		mes "[ムガン]";
		mes "待っていたぞ。";
		mes strcharinfo(0)+ "。";
		mes "ムヒョンから君の話は聞いている。";
		next;
		mes "[ムガン]";
		mes "ムヒョンを通さずに";
		mes "私を見つけだすこともできるが、";
		mes "見ての通り";
		mes "私は太陽と月と星の悪魔に出会った身。";
		mes "人を満足に見ることができない。";
		next;
		mes "[ムガン]";
		mes "ムヒョンの人を見る目は確かだ。";
		mes "そして、君はそのムヒョンが認めた者。";
		mes "太陽と月と星の代行人となり、";
		mes "君が持つ二つの足と二つの拳を";
		mes "使う心構えはできているか？";
		next;
		if(select("はい！　転職試験を受けます！","少しの間、時間をください")==2) {
			mes "[ムガン]";
			mes "準備するものがあるのか？";
			mes "夜は長く星も多い……";
			mes "今しばらく自然は待ってくれるだろう。";
			mes "君は拳聖になることを忘れるな。";
			close;
		}
		if(SkillPoint) {
			mes "[ムガン]";
			mes "スキルポイントが余っているな。";
			mes "君はまだ心の中にためらいがあるようだ。";
			next;
			mes "[ムガン]";
			mes "習得したスキルポイントを使いなさい。";
			mes "そうしなければ、";
			mes "拳聖になることはできない。";
			close;
		}
		mes "[ムガン]";
		mes "君は私たち拳聖について、";
		mes "その本質を理解しているか？";
		next;
		mes "[ムガン]";
		mes "目を閉じて自分が望むことを";
		mes "感じてみろ。";
		mes "両腕を開いて空を抱いてみろ。";
		next;
		mes "[ムガン]";
		mes "君の中の自然を感じられるか？";
		mes "君の胸は自然を感じられるか？";
		mes "君と一緒に呼吸する自然を感じられるか？";
		next;
		mes "[ムガン]";
		mes "私たちは太陽の光を抱き、";
		mes "星明かりで刀を作り、";
		mes "星明かりの様な鮮血を振り撒く。";
		next;
		mes "[ムガン]";
		mes "私たちは";
		mes "逆らうことができない自然の摂理で";
		mes "世を渡らなければならない存在だ。";
		mes "では、さっそく課題を与えよう。";
		next;
		mes "[ムガン]";
		mes "世界各地に散らばっている";
		mes "自然の力を集めて来い。";
		mes "風の切れ端、尊厳なる大地、";
		mes "凍れる水、灼熱の炎。";
		next;
		mes "[ムガン]";
		mes "これらは";
		mes "^3434FFラフウィンド";
		mes "グレイトネイチャ";
		mes "ミスティックフローズン";
		mes "フレイムハート^000000";
		mes "という名で存在している。";
		next;
		mes "[ムガン]";
		mes "君は拳聖となる前に";
		mes "どんな自然であろうとも";
		mes "捕らえる事ができるという";
		mes "その証拠を持って来い。";
		mes "これが拳聖になるための最初の試験だ。";
		set CHANGE_SG,2;
		close;
	case 2:
		if(countitem(996) < 1 || countitem(997) < 1 || countitem(995) < 1 || countitem(994) < 1) {
			mes "[ムガン]";
			mes "どうした。";
			mes "君が出会い、感じ、";
			mes "経験してきた自然を持って来るんだ。";
			mes "自然が持つ無限の力は";
			mes "凝縮されながらもこの世界の";
			mes "どこかに散らばっているんだ。";
			next;
			mes "[ムガン]";
			mes "君を撫でゆく空気を思え。";
			mes "君が踏んでいるこの大地を思え。";
			next;
			mes "[ムガン]";
			mes "耳元を鳴らした川辺の流れを思え。";
			mes "熱い胸のような暖かさを思え。";
			next;
			mes "[ムガン]";
			mes "それは感じられないが";
			mes "感じられること。";
			mes "それは目に見えないが見えること。";
			next;
			mes "[ムガン]";
			mes "あまりにも当然のように私たちを";
			mes "抱いているが、感じることができない。";
			mes "あまりにも巨大に私たちを";
			mes "包んでいるのに、見ることができない。";
			next;
			mes "[ムガン]";
			mes "それが自然という存在だ。";
			mes "太陽と月と星の戦士は";
			mes "すなわち自然の戦士だ。";
			mes "………………";
			mes "君の行動に期待しよう。";
			close;
		}
		mes "[ムガン]";
		mes "よく戻ってきた。";
		mes "さっそくだが、";
		mes "君はこれらを見て";
		mes "何か感じる事ができたか？";
		next;
		mes "[ムガン]";
		mes "共に呼吸しながらも共存し、";
		mes "刹那の瞬間に隠した刃をつきいれる風。";
		mes "皆の下にあるが";
		mes "世界を覆すことができる脈動の大地。";
		next;
		mes "[ムガン]";
		mes "無限に下へ流れるが";
		mes "自分を変化させ、冷える息づかいで";
		mes "脅威となる水。";
		mes "その踊り狂う身をもって";
		mes "再生と破壊を司る火。";
		next;
		mes "[ムガン]";
		mes "これが自然だ。";
		mes "私たちが敬わなければならない存在。";
		mes "そしてその全てのものの上には";
		next;
		mes "[ムガン]";
		mes "^3434FF太陽と^000000";
		next;
		mes "[ムガン]";
		mes "^3434FF月と^000000";
		next;
		mes "[ムガン]";
		mes "^3434FF星明かりが^000000";
		next;
		mes "[ムガン]";
		mes "その無限の祝福で";
		mes "私たちを";
		mes "世界を";
		mes "大地を";
		mes "一杯に満たしているのだ。";
		next;
		mes "[ムガン]";
		mes "それでは、";
		mes "君を私たちの聖域へ案内しよう。";
		mes "一瞬の選択で運命を支え生きていく";
		mes "私たちの聖域だ。";
		next;
		mes "[ムガン]";
		mes "君はそこで見て、聞いて、感じたことを";
		mes "私に言うだけでいい。";
		mes "………………";
		mes "準備ができたら、";
		mes "また私の元へ来たまえ。";
		delitem 996,1;
		delitem 997,1;
		delitem 995,1;
		delitem 994,1;
		set CHANGE_SG,3;
		close;
	case 3:
		mes "[ムガン]";
		mes "準備はできたかね。";
		mes "太陽と月と星の戦士たちの聖域へ";
		mes "君は行くことになる。";
		next;
		if(select("少し、待ってください！","いつでもどうぞ")==1) {
			mes "[ムガン]";
			mes "分かった。";
			mes "準備ができたら呼ぶといい。";
			close;
		}
		mes "[ムガン]";
		mes "よし、行きたまえ。";
		mes "そこには別の担当者がいるだろう。";
		mes "全てが終わったら、";
		mes "私の元へ戻ってくることを忘れずに。";
		close2;
		savepoint "comodo",180,151;
		warp "job_star",34,12;
		end;
	default:
		mes "[ムガン]";
		mes "まだ山を下りる時ではない。";
		mes "もう一度聖域に行きなさい。";
		close2;
		warp "job_star",34,12;
		end;
	case 6:
		mes "[ムガン]";
		mes "顔に懸念が見えるな。";
		mes "しかし、答えは";
		mes "自分自身で導かなければならない。";
		mes "納得できる答えが見つかったら";
		mes "また来るがいい。";
		close;
	case 7:
		mes "[ムガン]";
		mes "ムヒョンの話はためになったか？";
		mes "今回の様な事は常にある事で、";
		mes "一つの関門のようなものだ。";
		mes "しかし、これを通じて";
		mes "自分の心を貫けるように";
		mes "したほうがいいぞ。";
		next;
		mes "[ムガン]";
		mes "ピリュが待っている。";
		mes "月の部屋に行かせよう。";
		mes "君は見て、聞いて、感じたことを";
		mes "全て私に言えるように";
		mes "心に刻みなさい。";
		close2;
		warp "job_star",100,13;
		end;
	case 10:
		mes "[ムガン]";
		mes "チヒのおつかいか。";
		mes "そんなものもあったな。";
		mes "君も苦労しているようだ。";
		next;
		mes "[ムガン]";
		mes "星の部屋に行くか？";
		mes "そうなら私が今すぐ送ってあげよう。";
		next;
		if(select("お願いします","まだいいです")==2) {
			mes "[ムガン]";
			mes "準備が終わればまた来なさい。";
			close;
		}
		mes "[ムガン]";
		mes "もうすぐまた";
		mes "私の元に来る事になるはずだ。";
		close2;
		warp "job_star",166,29;
		end;
	case 12:
		if(SkillPoint) {
			mes "[ムガン]";
			mes "スキルポイントが余っているな。";
			mes "君はまだ心の中にためらいがあるようだ。";
			next;
			mes "[ムガン]";
			mes "習得したスキルポイントを使いなさい。";
			mes "そうしなければ、";
			mes "拳聖になることはできない。";
			close;
		}
		mes "[ムガン]";
		mes "よく戻ってきたな。";
		mes "目つきが随分とよくなっているぞ。";
		mes "何を見て、何を感じてきた？";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "太陽と月と星が存在することを";
		mes "感じました。";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "太陽と月と星の暖かさを感じました。";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "太陽と月と星が与える";
		mes "安らかさを感じました。";
		next;
		mes "[ムガン]";
		mes "そして？";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "星の散々と散らばった悲しみを";
		mes "感じました。";
		mes "月の冷たい怒りを感じました。";
		mes "太陽は再生と破壊の化身でした。";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "太陽と月と星の怒りは";
		mes "すべてのものをより分ける";
		mes "悪魔を呼び出します。";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "しかし、太陽と月と星を友にすれば";
		mes "無限の祝福を与えられました。";
		next;
		mes "[" +strcharinfo(0)+ "]";
		mes "私の……この小さな体が";
		mes "宇宙の中に堂々と存在していました。";
		next;
		mes "[ムガン]";
		mes "立派になったな。";
		mes "君はもう";
		mes "太陽と月と星の戦士だ。";
		next;
		nude;
		jobchange Job_Star;
		set CHANGE_SG,0;
		mes "[ムガン]";
		mes "私たちの全員が、心より歓迎しよう。";
		next;
		mes "[ムガン]";
		mes "選択は慎重にするように。";
		mes "私たち拳聖はその選択によって";
		mes "一生の運命が決められる。";
		mes "そして、何度も聞いた歌を忘れるな。";
		next;
		mes "[ムガン]";
		mes "^3434FF太陽は偶数日に眩い光を出し、";
		mes "月は奇数日にその輝きを増し、";
		mes "星は五日目に夜を探し光を振り撒く。^000000";
		next;
		mes "[ムガン]";
		mes "私が君に望むことはこれだけだ。";
		mes "以後の生活は君の自由。";
		mes "私たち拳聖は、太陽と月と星がある限り";
		mes "その空の下にあるというのを";
		mes "忘れないように。";
		close;
	}
}

//==========================================
// 試験
//------------------------------------------

job_star,29,33,0	script	タル	59,{
	if(Job != Job_Taekwon) {
		mes "[タル]";
		mes "転職試験を邪魔しないでくださいね。";
		mes "村に戻りますか？";
		next;
		if(select("村に戻る","いいえ")==2) {
			mes "[タル]";
			mes "そうですか。";
			close;
		}
		mes "[タル]";
		mes "分かりました。";
		mes "村に送ってさしあげます。";
		close2;
		warp "payon",164,58;
		end;
	}
	switch(CHANGE_SG) {
	case 3:
		mes "[タル]";
		mes "ムガン先生に送られた方ですね。";
		mes "太陽の部屋にようこそ。";
		mes "私はここであなたの";
		mes "お手伝いをするように言われています。";
		next;
		mes "[タル]";
		mes "それでは始めますね。";
		mes "今あなたの目の前には何がありますか？";
		next;
		switch(select("太陽","月","星","分からない")) {
		case 1:
			mes "[タル]";
			mes "正解です。あれは太陽です。";
			mes "そして堂々と太陽と向い合った";
			mes "私たちも太陽なのです。";
			set .@test,.@test+1;
			break;
		case 2:
			mes "[タル]";
			mes "月ですか……";
			mes "ここは太陽の部屋だと言ったでしょう。";
			break;
		case 3:
			mes "[タル]";
			mes "星ですか。";
			mes "確かに太陽も宇宙に存在する";
			mes "幾多の中の星ですね。";
			break;
		case 4:
			mes "[タル]";
			mes "そうですか……";
			mes "もうちょっと心を開いて";
			mes "想像力を豊かにした方が良いですね。";
			break;
		}
		next;
		mes "[タル]";
		mes "草木は太陽の光を受けて";
		mes "生命を作ります。";
		mes "あなたは太陽から何をもらいますか？";
		next;
		switch(select("温もり","安楽","祝福","何ももらわない")) {
		case 1:
			mes "[タル]";
			mes "そうです。";
			mes "私たちはその無限の光から";
			mes "暖かい温もりを与えられています。";
			set .@test,.@test+1;
			break;
		case 2:
			mes "[タル]";
			mes "そうです。";
			mes "私たちは明るい光の中にいる時、";
			mes "心の不安を拭い去り、平穏を得ます。";
			set .@test,.@test+1;
			break;
		case 3:
			mes "[タル]";
			mes "そうです。";
			mes "草木が太陽の祝福で生命を作るように";
			mes "私たちも祝福を与えられています。";
			set .@test,.@test+1;
			break;
		case 4:
			mes "[タル]";
			mes "頭ではなく";
			mes "胸の中で考えて見てください。";
			mes "あなたにも間違いなく";
			mes "太陽から受けた何かがあるはずです。";
			break;
		}
		next;
		mes "[タル]";
		mes "こんな歌があります。";
		mes "^3434FF太陽は偶数日に眩い光を出し、";
		mes "月は奇数日にその輝きを増し、";
		mes "星は五日目に夜を探し光を振り撒く。^000000";
		next;
		mes "[タル]";
		mes "あなたは太陽の場所を砂漠に、";
		mes "太陽の憎悪を蟻に与えた。";
		mes "あなたは月の場所を沼地に、";
		mes "月の憎悪をワニに与えた。";
		mes "あなたは星の場所を古城に、";
		mes "星の憎悪を黒い騎士に与えました。";
		next;
		mes "[タル]";
		mes "君が一番明るく輝くことができる日は";
		mes "どの時ですか？";
		next;
		if(select("2日、沼地、黒い騎士","4日、砂漠、蟻","10日、砂漠、黒い騎士","5日、沼地、ワニ")==2)
			set .@test,.@test+1;
		mes "[タル]";
		mes "ふむ、この位で十分ですね。";
		mes "この三つの質問で";
		mes "試験を左右することはありません。";
		mes "安心してください。";
		next;
		if(.@test >= 2) {
			mes "[タル]";
			mes "あなたは……";
			mes "太陽の光が";
			mes "私たちから始まったということを";
			mes "信じますか？";
			next;
			mes "[タル]";
			mes "太陽の光を";
			mes "私たちの手で守らなければならない";
			mes "ということを信じますか？";
			next;
			mes "[タル]";
			mes "私はあなたの事を信じます。";
			mes "太陽の戦士になって";
			mes "太陽の暖かさを、安らかさを、";
			mes "祝福をその両手で受け止められることを。";
			next;
			mes "[タル]";
			mes "それでは、あなたを";
			mes "「月の部屋」に";
			mes "送ってさしあげましょう。";
			set CHANGE_SG,5;
			close2;
			warp "job_star",100,13;
			end;
		}
		else {
			mes "[タル]";
			mes "あなたは……";
			mes "太陽をありのままの";
			mes "自然の存在だと";
			mes "決め付けないでください。";
			next;
			mes "[タル]";
			mes "あなたの世界で、";
			mes "あなたと一緒に呼吸し、";
			mes "共に生きて行く";
			mes "両親のような存在なのです。";
			next;
			mes "[タル]";
			mes "あなたはもう少し";
			mes "太陽を理解する必要があります。";
			mes "そこに座って";
			mes "太陽の偉大さを感じてください。";
			set CHANGE_SG,4;
			close;
		}
	case 4:
		if(rand(5)) {
			mes "[タル]";
			mes "静かに心を沈め……";
			mes "目をつむって……";
			mes "徐々に近付く";
			mes "太陽の暖かさを感じてください。";
			next;
			mes "[タル]";
			mes "次の話は太陽を存分に";
			mes "感じれた後に続けることにします。";
			close;
		}
		mes "[タル]";
		mes "太陽がどんな存在なのか";
		mes "分かりましたか？";
		mes "頭で理解するよりも";
		mes "胸で感じる方がもっと重要です。";
		next;
		mes "[タル]";
		mes "お疲れ様でした。";
		mes "十分に理解していると信じて";
		mes "月の部屋へ送ってさしあげます。";
		set @star_test,0;
		set CHANGE_SG,5;
		close2;
		warp "job_star",100,13;
		end;
	case 5:
	case 6:
		mes "[タル]";
		mes "どうしてまだ";
		mes "ここにいるのですか？";
		mes "月の部屋に送ってさしあげます。";
		close2;
		warp "job_star",100,13;
		end;
	default:
		mes "[タル]";
		mes "太陽の部屋が気に入りましたか？";
		mes "それとも、道に迷ったのですか？";
		mes "あなたは今、「星の部屋」に";
		mes "いなければなりません。";
		next;
		mes "[タル]";
		mes "星の部屋に送ってさしあげます。";
		close2;
		warp "job_star",166,29;
		end;
	}
}

job_star,95,33,0	script	ピリュ	106,{
	if(Job != Job_Taekwon) {
		mes "[ピリュ]";
		mes "転職試験の邪魔になる。";
		mes "黙っていられないなら村に帰れ。";
		mes "今すぐ戻るか？";
		next;
		if(select("村に戻る","いいえ")==2) {
			mes "[ピリュ]";
			mes "………………";
			mes "そうか……邪魔をするなよ。";
			close;
		}
		mes "[ピリュ]";
		mes "村に送ってやる。";
		close2;
		warp "payon",164,58;
		end;
	}
	switch(CHANGE_SG) {
	case 5:
		mes "[ピリュ]";
		mes "はやく来なさい。";
		mes "月の影になる者よ。";
		mes "今からこのピリュが相手をする。";
		next;
		mes "[ピリュ]";
		mes "問おう。";
		mes "私たちに必要な月はどのような月か？";
		mes "お前の願う月はどのような月か？";
		next;
		switch(select("赤い月","青い月","黄色い月","……？")) {
		case 1:
			mes "[ピリュ]";
			mes "赤い月だと……";
			mes "血を抱く事を願うか？";
			mes "狂気は遠ざけた方が良い。";
			break;
		case 2:
			mes "[ピリュ]";
			mes "物静かに青みをたたえる月は";
			mes "心を落ち着かせ";
			mes "冷静な自分を探してくれる。";
			mes "良い選択だ。";
			set .@test,.@test+1;
			break;
		case 3:
			mes "[ピリュ]";
			mes "金に輝く月は、皆に豊穣を約束する。";
			mes "それは夜の主人が持つ豊かさを示す。";
			mes "悪くない選択だ。";
			set .@test,.@test+1;
			break;
		case 4:
			mes "[ピリュ]";
			mes "自分の意見を持つことは";
			mes "とても重要な事だ。";
			mes "もっと自信を持つ必要がある。";
			mes "まさか……月が嫌いか？";
			break;
		}
		next;
		mes "[ピリュ]";
		mes "お前が月の影になる";
		mes "その理由は何だ？";
		next;
		switch(select("正義実践","自己修練","自然保護","復讐")) {
		case 1:
			mes "[ピリュ]";
			mes "武術と力で正義を実践するのか？";
			mes "自分の信念を貫くためには";
			mes "力が必要だということは";
			mes "わかっているな。";
			set .@test,.@test+1;
			break;
		case 2:
			mes "[ピリュ]";
			mes "自分自身を治めることは";
			mes "とても重要な事だ。";
			mes "しかし、何故修練をするのかという";
			mes "その理由と目標は忘れてはいけない。";
			set .@test,.@test+1;
			break;
		case 3:
			mes "[ピリュ]";
			mes "………………勿論、";
			mes "自然を保護することは";
			mes "私たちの使命だ。";
			mes "しかし、月の影とならずとも";
			mes "自然保護はできる事だ。";
			break;
		case 4:
			mes "[ピリュ]";
			mes "青い月は静かな怒りを口にする。";
			mes "冷たい笑みの後、";
			mes "よく鍛えられた刃を振るう。";
			mes "まるで沈んだ湖のように…………";
			mes "だが……";
			next;
			mes "[ピリュ]";
			mes "復讐を終えた後、";
			mes "お前は何を支えに生きて行く？";
			mes "盲目的な復讐より、";
			mes "調和を学ばなければならないようだな。";
			break;
		}
		next;
		mes "[ピリュ]";
		mes "この歌を覚えているか？";
		mes "^3434FF太陽は偶数日に眩い光を出し、";
		mes "月は奇数日にその輝きを増し、";
		mes "星は五日目に夜を探し光を振り撒く。^000000";
		next;
		mes "[ピリュ]";
		mes "お前は太陽の場所を砂漠に、";
		mes "太陽の憎悪を蟻に与えた。";
		mes "お前は月の場所を沼地に、";
		mes "月の憎悪をワニに与えた。";
		mes "お前は星の場所を古城に、";
		mes "星の憎悪を黒い騎士に与えた。";
		next;
		mes "[ピリュ]";
		mes "お前が月の影として";
		mes "一番輝く時はいつだ？";
		next;
		if(select("2日、沼地、黒い騎士","4日、砂漠、蟻","10日、砂漠、黒い騎士","5日、沼地、ワニ")==4)
			set .@test,.@test+1;
		mes "[ピリュ]";
		mes "簡単な質問はこの位にする。";
		next;
		if(.@test >= 2) {
			mes "[ピリュ]";
			mes "お前は……";
			mes "月の影がどんな存在なのか";
			mes "静かで物静かな月明りが";
			mes "何を意味しているのか";
			mes "理解しなければならない。";
			next;
			mes "[ピリュ]";
			mes "太陽の熱い情熱が";
			mes "お前の心を焼き尽くさないよう";
			mes "存在するのが冷たい月だ。";
			mes "お前はそのような";
			mes "月の影にならなければならない。";
			next;
			mes "[ピリュ]";
			mes "月の影となり";
			mes "皆の怒りを受け入れ、";
			mes "月の戦士として";
			mes "彼らの代わりに";
			mes "戦わなければならない。";
			next;
			mes "[ピリュ]";
			mes "私は同じ事を二度も言わない。";
			mes "それは太陽の戦士も、";
			mes "月の影も、星の涙も同じだ。";
			next;
			mes "[ピリュ]";
			mes "人は誰もが、";
			mes "常に選択の岐路に立っている。";
			mes "そして、振り返る事ができない選択で";
			mes "一生をかけなければならないのが";
			mes "まさに私たち、拳聖だ。";
			next;
			mes "[ピリュ]";
			mes "私はお前が後悔しない道を";
			mes "進むことを願っている。";
			mes "それでは、星の部屋に行く";
			mes "資格を与えよう。";
			set CHANGE_SG,8;
			close2;
			warp "job_star",166,29;
			end;
		}
		else {
			mes "[ピリュ]";
			mes "お前は……";
			mes "青い月明りが意味することを";
			mes "もっと理解しなければならない。";
			next;
			mes "[ピリュ]";
			mes "短絡的な心では、月の代わりとして";
			mes "争うことはできない。";
			mes "お前は忍耐力を育てなければならず、";
			mes "常にその場に留まれる平常心を";
			mes "養わなければならない。";
			next;
			mes "[ピリュ]";
			mes "私は同じ道を二度も言わない。";
			mes "それは太陽の戦士も、";
			mes "月の影も、星の涙も同じだ。";
			next;
			mes "[ピリュ]";
			mes "人は誰もが、";
			mes "常に選択の岐路に立っている。";
			mes "そして、振り返る事ができない選択で";
			mes "一生をかけなければならないのが";
			mes "まさに私たち、拳聖だ。";
			next;
			mes "[ピリュ]";
			mes "それでも後悔しない道を歩むというなら";
			mes "その証拠を私に見せなさい。";
			set CHANGE_SG,6;
			close2;
			warp "payon",164,58;
			end;
		}
	case 7:
		mes "[ピリュ]";
		mes "……………………ふふ。";
		mes "少し待ちくたびれたぞ。";
		mes "もし帰ってこれなかったら、";
		mes "お前は一生後悔しながら";
		mes "生きていく所だったぞ。";
		next;
		mes "[ピリュ]";
		mes "後悔しない人生には「根性」が必要だ。";
		mes "「忍耐力」、「包容力」、";
		mes "そして、その全てを支えることができる";
		mes "「理解」と挑戦のための「根性」。";
		next;
		mes "[ピリュ]";
		mes "力に自分が捕らわれる前に";
		mes "自分の心を鍛え、逆に力を";
		mes "支配しなければならない。";
		mes "自分の信念を曲げずに";
		mes "人間は堂々と空を仰ぎながら";
		mes "生きていくべきなのだ。";
		next;
		mes "[ピリュ]";
		mes "後悔しない人生。";
		mes "それを進むのがまさに私たち拳聖だ！";
		mes "倒れてもまた起き上がれたお前に";
		mes "星の部屋へ行く";
		mes "資格を与えよう！";
		set CHANGE_SG,8;
		close2;
		warp "payon",164,58;
		end;
	default:
		mes "[ピリュ]";
		mes "なぜここに残っている？";
		mes "青い満月でも気に入ったか？";
		mes "わからんでもないが、";
		mes "お前は拳聖になるための試験を";
		mes "受けているのではないのか？";
		next;
		mes "[ピリュ]";
		mes "星の部屋に送ってやる。";
		close2;
		warp "job_star",166,29;
		end;
	}
}

job_star,161,33,0	script	チヒ	77,{
	if(Job != Job_Taekwon) {
		mes "[チヒ]";
		mes "星明かりが美しいでしょう？";
		mes "村へ戻りますか？";
		next;
		if(select("村に戻る","いいえ")==2) {
			mes "[チヒ]";
			mes "そうですか。";
			close;
		}
		mes "[チヒ]";
		mes "分かりました。";
		mes "村へ戻してあげます。";
		close2;
		warp "payon",164,58;
		end;
	}
	switch(CHANGE_SG) {
	case 8:
		mes "[チヒ]";
		mes "どうですか？";
		mes "星明かりが本当に";
		mes "きれいじゃないですか？";
		next;
		mes "[チヒ]";
		mes "まるで黒いカーテンに散らばる";
		mes "少女の涙の様に思えてきます。";
		set CHANGE_SG,9;
		close;
	case 9:
		if(rand(3)) {
			mes "[チヒ]";
			mes "…………………………";
			mes "…………………………";
			next;
			mes "-彼女は空の星から目を離さない-";
			close;
		}
		mes "[チヒ]";
		mes "地上であの星を";
		mes "手にすることができますか？";
		mes "散らせばほこりのように消えてしまう";
		mes "この星々を手にすることができますか？";
		set CHANGE_SG,10;
		close;
	case 10:
		if(countitem(1000) < 1 || countitem(1001) < 1) {
			mes "[チヒ]";
			mes "星のかけら……そして星の粉。";
			mes "ここでは手に入れることができません。";
			mes "一度下山して手に入れて来てください。";
			close2;
			warp "payon",164,58;
			end;
		}
		mes "[チヒ]";
		mes "お待たせしました。";
		mes "人々はこのような星で";
		mes "鉄を鍛えてますね。";
		next;
		mes "[チヒ]";
		mes "臆病に日々をおくる人間は、";
		mes "星の力で人を、命を、万物を";
		mes "守ろうとします。";
		next;
		mes "[チヒ]";
		mes "そして、鉄になった星は";
		mes "生命を奪い取ることで";
		mes "他の生命を守ることになります。";
		next;
		mes "[チヒ]";
		mes "これは悲しい事です。";
		mes "しかし、これが現実という事は";
		mes "頭で理解できますね？";
		next;
		mes "[チヒ]";
		mes "天の川を流れる光が";
		mes "美しいと思いませんか？";
		mes "しかし、あれは消えていった命が";
		mes "空で繋ぎ合って生まれた星の涙です。";
		next;
		mes "[チヒ]";
		mes "太陽の機運を得て";
		mes "月の機運を得て";
		mes "星の機運を得ようと";
		mes "してください……";
		next;
		mes "[チヒ]";
		mes "それではお聞きします。";
		mes "あなたは誰の涙の代わりに";
		mes "血を流そうと思いますか？";
		delitem 1000,1;
		delitem 1001,1;
		set CHANGE_SG,11;
		close;
	case 11:
		mes "[チヒ]";
		mes "考えてみましたか？";
		mes "難しい質問ではなかったはずです。";
		mes "血を流した者には、";
		mes "常に涙が共にいることを";
		mes "わかっているか聞いてみただけです。";
		next;
		mes "[チヒ]";
		mes "^3434FF太陽は偶数日に眩い光を出し、";
		mes "月は奇数日にその輝きを増し、";
		mes "星は五日目に夜を探し光を振り撒く。^000000";
		mes "この歌は聞いていますね？";
		next;
		mes "[チヒ]";
		mes "あなたは太陽の場所を砂漠に";
		mes "太陽の憎悪を蟻に与えた。";
		mes "あなたは月の場所を沼地に";
		mes "月の憎悪をワニに与えた。";
		mes "あなたは星の場所を古城に";
		mes "星の憎悪を黒い騎士に与えた。";
		next;
		mes "[チヒ]";
		mes "あなたから一番星の明かりが明るく";
		mes "輝く時は何時であるか";
		mes "ご存じですか？";
		next;
		if(select("5日、古城、蟻","10日、砂漠、蟻","25日、古城、黒い騎士","10日、砂漠、黒い騎士")==3) {
			mes "[チヒ]";
			mes "わかっているようですね。";
			mes "星は宇宙を周期的に回り、";
			mes "私たちを訪ねにきます。";
			mes "太陽に立ち向かい、自らが";
			mes "一つの太陽になるのが偶数の日。";
			next;
			mes "[チヒ]";
			mes "月と一つになり、";
			mes "影となるのが奇数の日。";
			mes "星が自ら私たちを訪ねるのが五日目。";
			next;
			mes "[チヒ]";
			mes "五日に一度訪れる星明かりは";
			mes "私たちに祝福を授けてくれます。";
			mes "星の日、星の場所、";
			mes "そして星の憎悪が授けられた存在。";
			next;
			mes "[チヒ]";
			mes "その日こそが、";
			mes "あなたが一番強く輝ける日です。";
			mes "拳聖は太陽と月と星の";
			mes "感情と暖かさと憎悪を";
			mes "もっと理解しなければなりません。";
			next;
			mes "[チヒ]";
			mes "先ほどの歌には";
			mes "太陽と月と星と私たちの原理が";
			mes "皆にかかっているのです。";
			mes "ゆっくりと考えて、";
			mes "何を意味しているか理解してください。";
		}
		else {
			mes "[チヒ]";
			mes "拳聖は太陽と月と星の";
			mes "感情と暖かさと憎悪を";
			mes "もっと理解しなければなりません。";
			next;
			mes "[チヒ]";
			mes "太陽と月と星と私たちの原理が";
			mes "皆にかかっているのです。";
			mes "ゆっくりと考えて、";
			mes "何を意味しているか理解してください。";
		}
		next;
		mes "[チヒ]";
		mes "拳聖になっても、忘れずに";
		mes "その意味を振り返り";
		mes "後悔しない選択を";
		mes "選ばなければなりません。";
		next;
		mes "[チヒ]";
		mes "十分に星明かりを感じ、";
		mes "満足していると思えたのなら、";
		mes "ムガン先生の所まで";
		mes "お送りします。";
		set CHANGE_SG,12;
		close;
	case 12:
		mes "[チヒ]";
		mes "山を下りますか？";
		next;
		if(select("はい","いいえ")==2) {
			mes "[チヒ]";
			mes "星明かりで心をいっぱいに満たすまで";
			mes "いくらでもここにいて良いのですよ。";
			mes "のびやかに、ゆっくりと、";
			mes "将来に後悔がないように…………";
			close;
		}
		mes "[チヒ]";
		mes "近くの村に送ってあげます。";
		close2;
		warp "payon",164,58;
		end;
	}
}
