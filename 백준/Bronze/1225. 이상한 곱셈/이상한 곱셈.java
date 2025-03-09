import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		String A = st.nextToken();
		String B = st.nextToken();
		//곱해서 나온 값을 더해줄 정수형 변수.(long)
		long result = 0;
		
		//각 입력값의 문자열 길이만큼 반복하는 반복문안에서 연산해준다.
		for(int i = 0; i < A.length(); i++) {
			for(int j = 0; j < B.length(); j++) {
				result += (A.charAt(i) - '0') * (B.charAt(j) - '0');
			}
		}
		System.out.println(result);
	}

}