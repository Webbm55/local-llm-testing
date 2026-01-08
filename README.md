# Local LLM Testing Repository

This repository is dedicated to testing and experimenting with local large language models (LLMs) using **LM Studio** on a local machine.

## Purpose
The main goal of this repo is to:
- Test different LM models locally for performance, accuracy, and use cases
- Experiment with prompts, inputs, and model configurations
- Document findings and results from local LLM testing
- Serve as a sandbox for trying out new features or models without affecting production environments

## Tools Used
- **LM Studio**: A powerful tool for running large language models locally on your machine.
  - [Official LM Studio Website](https://lm-studio.ai/)
  - Supports various model types (e.g., Mistral, LLaMA, etc.)

## Getting Started
### Prerequisites
1. **LM Studio** installed on your local machine.
   - Download from the [official website](https://lm-studio.ai/).
2. A compatible GPU (NVIDIA recommended) with sufficient VRAM for the models you want to test.
3. Python 3.8 or higher (for running scripts like `hello_world.py`).

### Setup Instructions
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/local-llm-testing.git
   cd local-llm-testing
   ```
2. Install LM Studio and set it up according to the [official documentation](https://lm-studio.ai/docs).
3. Run the provided scripts (e.g., `hello_world.py`) using Python:
   ```bash
   python hello_world.py
   ```
4. Use LM Studio to load and test different models locally.

## Repository Structure
```
local-llm-testing/
├── README.md          # This file
├── hello_world.py      # Example script for testing basic LLM interactions
└── .github/agents/     # Configuration files for local LLM testing
    └── Local LLM.agent.md  # Agent configuration (if applicable)
```

## Usage Examples
### Running the Hello World Script
1. Open a terminal in this directory.
2. Run the script:
   ```bash
   python hello_world.py
   ```
3. Enter your name and age when prompted to see how the model interacts with simple inputs.

### Testing Models in LM Studio
1. Open LM Studio.
2. Load a model (e.g., Mistral 7B or another supported model).
3. Experiment with prompts, inputs, and configurations.
4. Document your findings in this repository for future reference.

---