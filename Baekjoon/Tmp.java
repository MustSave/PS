package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Tmp {
	static List<String> word=new ArrayList<>();
	static List<Character> answer;
	static StringBuilder sb=new StringBuilder();
	static Map<Character,Integer> dic;



	public static void main(String[] args) throws IOException {
		Map<Character, Integer> dic = new HashMap<>();
		dic.put('g', 1);
		dic.put('h', 1);
		dic.put('e', 1);
		dic.put('b', 1);
		dic.put('d', 1);
		dic.put('i', 1);
		dic.put('f', 1);
		dic.put('c', 1);
		dic.put('j', 1);
		dic.put('a', 1);

		for(Character c: dic.keySet()) {
			System.out.println(c);
		}
	}


	static public void permu(int cnt,int limit){
		if(cnt==limit){ //단어 길이만큼 완성되면 출력.
			for (Character c : answer) {
				sb.append(c);
			}
			sb.append("\n");
			return;
		}


		for (Character c : dic.keySet()) {
			if(dic.get(c)==0){ //알파벳 개수가 0개면 pass
				continue;
			}

			dic.put(c,dic.get(c)-1); //알파벳 사용
			answer.add(c); //answer에 붙여줌
			permu(cnt+1,limit); //재귀 (cnt+1)
			dic.put(c,dic.get(c)+1); //사용한 알파벳 원복
			answer.remove(answer.size()-1); //answer에 붙였던거 떼기

		}

	}
}
