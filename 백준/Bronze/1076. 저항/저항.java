import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//색을 순서대로 집어넣은 String 형의 배열
		String[] color = {"black", "brown", "red", "orange", "yellow", "green",
				"blue", "violet", "grey", "white"};
		
		String A = br.readLine();
		String B = br.readLine();
		String C = br.readLine();
		
		//인덱스값은 정수이기 때문에 처음 수에는 *10을 해주고 두번째 값과 더해준다.
		long result = (Arrays.asList(color).indexOf(A) * 10) + Arrays.asList(color).indexOf(B);
		//한번에 연산하기에 너무 길어지니 두줄로 나눈다.
		//첫번째값과 두번째값에 해당한 값을 구했으니 그 값에 세번째 값을 곱해준다.
		result *= Math.pow(10, Arrays.asList(color).indexOf(C));
		
		System.out.println(result);
	}

}