# Engineering Notes

## GitHub Actions -- Project Board Export Workflow Failure

## Problem
The GitHub Actions workflow responsible for exporting the GitHub Project Kanban board into a Markdown status document repeatedly failed during workflow execution.

### Primary Errors Included:
error: your authentication token is missing required scopes
### Later Errors:
remote: Permission to <repo> denied to github-actions[bot]
fatal: unable to access repository: 403

### Additional failures included:
- invalid YAML workflow syntax
- incorrect permission declarations
- malformed shell commands
- workflow parsing failures

## Root Cause
Several independent issues contributed to the workflow failures:

### 1. Insufficient PAT Scopes
The GitHub Personal Access Token (PAT) used by the workflow lacked required scopes for GitHub Projects API access.

Missing scopes included:
- read:org
- read:discussion
- project

### 2. Incorrect Workflow Permissions
The workflow initially lacked:
```txt
permissions:
  contents: write
```
which prevented GitHub Actions from pushing generated files back to the repository.

### 3. Invalid Workflow YAML Structure
Improper indentation and unsupported permission keys caused GitHub Actions to reject the workflow file.

Example issue:
```txt
projects: read
```
is not a valid GitHub Actions workflow permission.

### 4. Shell Script Formatting Errors
Malformed quoting inside shell commands caused execution failures.

Example:
```txt
git config --global user.email '41898282+github-actions[bot]@users.noreply.github.com'
```
had incorrect quoting during earlier iterations.

## Solution
### PAT Regeneration
The Personal Access Token was regenerated with the required scopes:
- repo
- read:org
- read:discussion
- project

The updated token replaced the repository secret:
```txt
PROJECT_ACCESS_TOKEN
```

### Workflow Permission Fix
The workflow permissions block was corrected to:
```txt
permissions:
  contents: write
```

### YAML Validation
The workflow YAML file was validated using:
```txt
yamllint .github/workflows/export-kanban.yml
```

### Additional formatting cleanup included:
- fixing indentation
- removing trailing whitespace
- correcting workflow structure

### Shell Command Corrections
Git configuration commands were corrected to valid shell syntax.

### Final Result
The GitHub Actions workflow successfully:
- accessed GitHub Project board data
- generated BOARD_STATUS.md
- committed generated updates
- pushed changes back to the repository automatically

## Lessons Learned
- GitHub Projects API access requires additional PAT scopes beyond standard repository permissions.
- GitHub Actions workflow permissions are separate from PAT permissions.
- YAML indentation errors can invalidate entire workflows.
- yamllint is useful for validating GitHub Actions workflow syntax locally.
- Architecture/process automation introduces operational complexity that should be documented early.

---

# Architecture Decisions

---

# Performance Observation

---

# Implementation Notes

---

# Debugging findings

---

# CI/CD Learnings

---

# Design Rationale
