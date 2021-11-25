import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		// 난이도의 문제 받기
		int[] questions = new int[N];
		String str = br.readLine();
		String[] split = str.split(" ");
		for(int i = 0; i < N; ++i){
			questions[i] = Integer.parseInt(split[i]);
		}
		
		Arrays.sort(questions);
		
		int count = 1;
		int before = questions[0];
		for(int i : questions){
			if(before != i)
				count++;
			else if (count == 3)
				break;
			before = i;
		}
		if(count < 3)
			System.out.print("NO");
		else
			System.out.print("YES");
		
		br.close();
	}
}