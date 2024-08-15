package com.ianskenny.memorymodel;

public class Computation {

	private Operation operation;
	private Evaluator evaluator;
	private int bufferIndex;
	
	public Computation(Operation op, Evaluator eval) {
		operation = op;
		evaluator = eval;
	}

	public Operation getOperation() {
		return operation;
	}

	public int getBufferIndex() {
		return bufferIndex;
	}

	public void setBufferIndex(int bufferIndex) {
		this.bufferIndex = bufferIndex;
	}

	public Evaluator getEvaluator() {
		return evaluator;
	}	
}
