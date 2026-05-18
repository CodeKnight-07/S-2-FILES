# S-2-FILES
This project features a competitive programming problem made by me for the PClub (IITK) Secretary Recruitment task, tenure 2026-27.


Problem statement- 
Submission Protocol: GitHub repo + Live deployment on Polygon.

"In our line of work, we don't just solve puzzles put in front of us. We build the mazes, and define the constraints. There are many paths through this shadow war, and you will encounter several of our operatives offering you different vectors of approach. Choose your battles wisely." - The Elk


PART A: THE ARCHITECTURE 

You are to design an original competitive programming problem from scratch. Your payload must include the following components, stored securely in a private GitHub repository (to be made public only after the deadline):

The Statement: Written as a .md file, strictly mirroring the stylistic conventions of Codeforces problem statements.

Test Case Generator: The code that procedurally generates test cases conforming to your exact constraints. You must use the `testlib` library. (Refer to the official testlib blogs and example generators for guidance).
The Solution: Preferably optimized in C++.

Editorial: A `.md` file containing a rigorous explanation of the algorithmic logic and time complexity. You must use LaTeX for all mathematical formulas and derivations.

Custom Checker: Required only if your operational parameters allow for multiple correct outputs.


PART B: THE UPLINK 

"In the domains where we operate, ideas aren't transmitted by thought. They require a staging ground." - The Fox

Follow the standard Polygon deployment tutorials to establish your foothold. You must execute the following sequence precisely:

1. Initialize: Upload your problem statement.
2. Document: Add your editorial to the Tutorial section of the problem.
3. Inject: Upload your C++ solution and the `testlib` generator. A validator is optional, but only if you are absolutely certain your generator never violates the constraints. Don't get sloppy.
4. Verify: Add a checker-either your custom build or one of Polygon's built-in verifiers.
5. Commit: Lock in your changes using the commit button at the bottom of the right panel.

Clearance Protocols:
You must grant the Syndicate oversight. Under "Manage Access", configure the following:
READ access to user: `codeforces`
WRITE access to users: `SuuvannAroraa` and `kingpsi3`

Final Deployment:
Under Packages, create a Standard package.
Extract the Polygon problem link 
Format:
https://polygon.codeforces.com/<id>/<username>/<problem-name>
Embed this link directly into the `README.md` of your GitHub repository.

EVALUATION PARAMETERS 

Editorial Quality: We will be heavily weighing this. We require a clear, well-structured, and mathematically accurate explanation of the thought process.

Originality: It’s very easy to leave a trail, and easier to get caught doing so. The problem must be completely original. It is your responsibility to verify that your problem (or a closely related variant) does not already exist in the wild.

Technical Execution: Correctness of the solution is a must. Your generators must be robust, producing valid test cases that aggressively cover maximum constraints and obscure edge cases.

While not strictly required, initiating advanced concepts will earn you Syndicate favor: the not-so-exhaustive list may include architecting interactive/communication type problems, setting up aggressive stress-testing scripts, writing complex custom checkers, deploying a highly unconventional algorithmic solution, etc.
