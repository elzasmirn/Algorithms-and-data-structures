/*Офисное здание
В одной очень большой стране в одном очень большом городе стояло очень-очень большое здание, в котором граждане этой страны подавали жалобы на других граждан. Так как жалобщиков было очень много, оно работало круглосуточно, но каждый из посетителей, пришедших в какое-то время после нуля часов, был обязан покинуть здание до 24 часов.
Клерков, принимающих жалобы, было не очень много, из-за чего гражданам приходилось сидеть и ждать в очереди, пока нужный клерк освободится.
На эту организацию, принимающую жалобы, в неё же поступила жалоба, что жалобы рассматриваются недостаточно быстро и вам было поручено определить, а сколько же жалобщиков одновременно находится в здании. К счастью для вас, во всех жителей этой страны были встроены чипы, точно определяющие положение в любой момент времени.
Вам был дан доступ к данным за сутки. В 00:00:00 здание жалобщиков не ещё не содержало, а в 24:00:00 уже не содержало, так как все жалующиеся покинули здание. Дверей в здании много, поэтому вполне могли случаться такие ситуации, когда в одну и ту же секунду один жалобщик прибывал, а другой — покидал помещение. В таком случае оба считались находящимися в здании.
Ваша задача — определить максимальное число жалобщиков, одновременно находящихся в здании.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<pair<int, char> > set_of_seg;
    int in_h, in_m, in_s, out_h, out_m, out_s;
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> in_h >> c >> in_m >> c >> in_s;
        set_of_seg.push_back({(in_h * 3600 + in_m * 60 + in_s), 'i'}); // in
        cin >> out_h >> c >> out_m >> c >> out_s;
        set_of_seg.push_back({(out_h * 3600 + out_m * 60 + out_s), 'o'}); // out
    }
    sort(set_of_seg.begin(), set_of_seg.end());
    int cnt = 0, res = 0;
    for (int i = 0; i < set_of_seg.size(); i++)
    {
        if (set_of_seg[i].second == 'i')
        {
            cnt++;
            if (cnt > res) res = cnt;
        }
        if (set_of_seg[i].second == 'o') cnt--;
    }
    cout << res;
}