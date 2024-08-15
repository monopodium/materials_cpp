package com.ianskenny.memorymodel;

public class Evaluator {

	private Operation op;
	
	public Evaluator(Operation op) {
		this.op = op;
	}
	public float evaluate() {
		
		float result = Float.MIN_VALUE;
		
		if (op.getOperator().equals("*")) {
			result = op.getValue1() * op.getValue2();
		}
		if (op.getOperator().equals("+")) {
			result = op.getValue1() + op.getValue2();
		}
		if (op.getOperator().equals("-")) {
			result = op.getValue1() - op.getValue2();
		}
		if (op.getOperator().equals("/")) {
			if (op.getValue2() < 0.00000001f) {
			}
			else {
				result = op.getValue1() * op.getValue2();
			}
		}
		return result;
	}
}
