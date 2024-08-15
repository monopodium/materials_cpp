package com.ianskenny.memorymodel;

public class Operation {
	private int value1;
	private int value2;
	private String operator = "NOT_SET";
	
	public Operation (int v1, int v2, String op) {
		value1 = v1;
		value2 = v2;
		operator = op;
	}
	public int getValue1() {
		return value1;
	}
	public int getValue2() {
		return value2;
	}
	public String getOperator() {
		return operator;
	}
	
	public String toString() {
		return getValue1() + " " + getOperator() + " " + getValue2();
	}
}
